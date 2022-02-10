#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
//temp replace with ft_//printf 
//TODO replace with ft_versions
#include <stdio.h>
#include <strings.h>

//DEBUG 
#include <stdio.h>

typedef unsigned char	t_byte;

/* address where binary data received via signals should be written */
t_byte	*g_byteptr;

#define IGNORE_NEXT 0
#define SET_PID 1
#define RUN_PREVSET 2

static void	ft_killer(int cmd, pid_t next_pid)
{
	static pid_t	pid = 0;
	static int		ignore = 0;

	if (cmd == IGNORE_NEXT)
		ignore = 1;
	else if (cmd == RUN_PREVSET)
	{
		if (ignore)
			ignore = 0;
		else
		{
			write(2, "-", 1);
			kill(pid, SIGUSR1);
			pid = 0;
		}
	}
	else if (cmd == SET_PID)
		pid = next_pid;
}


/* handler for SIGUSRs * * wait for 8 SIGUSR1 or SIGUSR2 signals * interpret them as binary data to be written to 'g_byteptr' * 
 * Send SIGUSR1 back to client process to confirm reception 
 * after every signal 
 *
 * auto increment 'g_byteptr' for ease of writing to buffers */
static void	ft_getbyte(int signum, siginfo_t *info, void *not_used)
{
	static int		ibit = 0;
	static t_byte	cur_byte = 0x00;

	(void) not_used;
	if (signum == SIGUSR2)
	{
		write(2, "1", 1);
		cur_byte |= (0x80 >> ibit);
	}
	else
		write(2, "0", 1);
	++ibit;
	if (ibit == 8)
	{
		*(g_byteptr++) = cur_byte;
		dprintf(2, " -> %#x\n", cur_byte);
		ibit = 0;
		cur_byte = 0x00;
	}
	ft_killer(SET_PID, info->si_pid);
//	kill(info->si_pid, SIGUSR1);
}

/* wait for SIGUSRs until enough data has been received to fill
 * 'buff' with n bytes of binary data + one null byte to signal
 * end of transmission 
 * (i.e. 'buff' should be at least n + 1 bytes) */
static void	ft_fill_bindata(void *buff, size_t n)
{
	/*ft_*/bzero(buff, n);
	g_byteptr = buff;
	((t_byte *) buff)[n] = 0xff;
	ft_killer(IGNORE_NEXT, 0);
	while (((t_byte *) buff)[n] == 0xff)
	{
		write(2, "_", 1);
		ft_killer(RUN_PREVSET, 0);
		pause();
	}

//	TODO understand why this causes pbs
	if (((t_byte *) buff)[n] != 0x00)
		write(2, "Warning: malformed transmission\n", 32);
	return ;
}

/* wait for a 'message' to be transmitted 
 * ie :
 * * wait for a len to be transmitted
 * * alloc a fresh pointer with that length + 1
 * * fill it with bindata representing the message string
 *   and return it.
 *
 * implementation note: 
 * 'sz_buff' needs to be a 'size_t[2]' array instead of a 
 * 't_byte[sizeof(size_t) + 1]' array for alignment. */
static char	*ft_wait_message(void)
{
	size_t	sz_buff[2];
	char	*message;

	ft_fill_bindata(sz_buff, sizeof(size_t));
	message = malloc(sz_buff[0] + 1);
	if (!message)
	{
		write(2, "malloc error\n", 13);
		exit(-1);
	}
	ft_fill_bindata(message, sz_buff[0]);
	return (message);
}

int	main()
{
	pid_t				pid;
	char				*message;
	struct sigaction	act;

	pid = getpid();
	/*ft_*/printf("server pid: %d\n", pid);
	
	act.sa_sigaction = ft_getbyte;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&(act.sa_mask));
//	sigaddset(&act.sa_mask, SIGUSR1);
//	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	while(1)
	{
		message = ft_wait_message();
		/*ft_*/printf("%s\n", message);
		free(message);
	}
}

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

typedef unsigned char t_byte;

/* address where binary data received via signals should be written
 * NULL indicates the server is not ready to receive data */
t_byte	*g_writehead = NULL;

static void sigusrs_blocker(int how)
{
	sigset_t	set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigprocmask(how, &set, NULL);
}

//#define LOAD 0
//#define RELEASE 1
//static void	ft_sig_launcher(char cmd, pid_t next_pid)
//{
//	static char		ready = 0;
//	static pid_t	pid = 0;
//
//	if (ready)
//		dprintf(2, ".");
//	if (ready && (cmd == RELEASE))
//	{
//		dprintf(2, "sent confirm\n");
//		kill(pid, SIGUSR1);
//		ready = 0;
//	}
//	if (cmd == LOAD)
//	{
//		dprintf(2, "loaded thingy\n");
//		pid = next_pid;
//		ready = 1;
//	}
//}

/* sigaction handler for SIGUSR1/2 :
 * wait for 8 signal (interpret as bits) 
 * and write the resulting byte to 'g_writehead' */
static void	ft_bindata_hand(int signum, siginfo_t *info, void *not_used)
{
	static int		ibit = 0;
	static t_byte	cur_byte = 0x00;

	(void) not_used;
	kill(info->si_pid, SIGUSR1);
	if (signum == SIGUSR2)
		cur_byte |= (0x80 >> ibit);
//	dprintf(2, "got bit %c\n", (signum == SIGUSR1) ? '0' : '1'); // debug
	++ibit;
	if (ibit == 8) 
	{
		*g_writehead = cur_byte;
		ibit = 0;
		cur_byte = 0x00;
		++g_writehead;
	}
//	dprintf(2, "confirm reception\n"); // debug
}

static void	ft_fill_bindata(void *buff, size_t n)
{
	t_byte	*end_pos;

	g_writehead = buff;
	end_pos = (t_byte *) buff + n;
	*end_pos = 0xff;
	sigusrs_blocker(SIG_UNBLOCK);
//	dprintf(2, "ready to receive data\n"); // debug
	while (*end_pos == 0xff)
	{
//		dprintf(2, "status : %#4x", (unsigned int) *end_pos); // debug
		pause();
	}
	sigusrs_blocker(SIG_BLOCK);
	g_writehead = NULL;
	write(1, "ok\n", 3); //debug
	if (*end_pos != 0x00)
		write(2, "WARNING: bad transmission\n", 26);
}

static char	*ft_wait_message(size_t *mes_sz)
{
	size_t	sz_buff[2];
	char	*message;

	ft_fill_bindata(sz_buff, sizeof(size_t));
	dprintf(2, "expecting mess of sz %zu\n", sz_buff[0]);
	message = malloc(sz_buff[0] + 1);
	if (!message)
	{
		write(2, "ERROR (fatal): bad alloc\n", 25);
		exit (-1);
	}
	ft_fill_bindata(message, sz_buff[0]);
	if (mes_sz != NULL)
		*mes_sz = sz_buff[0];
	return (message);
}

int main()
{
	struct sigaction	act;
	size_t				sz;
	char				*message;

	// init sigaction
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_bindata_hand;

	// hook it
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	// listen for messages to print back
	while (1)
	{
		message = ft_wait_message(&sz);
		write(1, message, sz);
		write(1, "\n", 1);
		free(message);
	}
	// flow control should never reach here
	return (-1);
}

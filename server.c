#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
//temp replace with ft_//printf 
//TODO replace with ft_versions
#include <stdio.h>
#include <strings.h>


char	*g_buffer;

void	ft_sigs_to_bin(int signum)
{
	static int	ibit = 0;
	static char	cur_byte;

	if (signum == SIGUSR2)
		cur_byte |= (0x80 >> ibit);
	++ibit;
	if (ibit == 8)
	{
		ibit = 0;
		*(g_buffer++) = cur_byte;
		//printf("byte : %c\nwrite_at %p\n", cur_byte, g_buffer);
		cur_byte = 0x00;
	}
}

void	ft_nreceive(void *buff, size_t n)
{
	/*ft_*/bzero(buff, n);
	g_buffer = buff;
	((char *) buff)[n] = 0xff;
	while (((char *) buff)[n] != '\0')
	{
		//printf("terminator %d\n", ((char *) buff)[n]);
		pause();
	}
	//printf("received transmission\n");
}

int	main()
{
	pid_t	pid;
	size_t	sz_buff[2]; //extra space for null termination
	char	*str;

	// display pid
	pid = getpid();
	/*ft_*/printf("server pid: %d\n", pid);
	
	// hook signals
	signal(SIGUSR1, ft_sigs_to_bin);
	signal(SIGUSR2, ft_sigs_to_bin);

	// do the thing
	while(1)
	{
		ft_nreceive(sz_buff, sizeof(size_t));
		str = malloc(sz_buff[0] + 1);
		if (!str)
		{
			write(2, "malloc error\n", 13);
			exit(-1);
		}
		ft_nreceive(str, sz_buff[0]);
		write(1, str, sz_buff[0]);
		write(1, "\n", 1);
		free(str);
	}
}

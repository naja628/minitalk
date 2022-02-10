#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
//TODO replace with ft version
#include <string.h>

//debug 
#include <stdio.h>

typedef unsigned char	t_byte;

/* sighandler:  resume after a pause */
static void	ft_waky(int signum)
{
	write(2, ".", 1);
	return ;
}

static void	ft_transmit_byte(pid_t pid, t_byte byte)
{
	int ibit;

	ibit = 0;
	while (ibit < 8)
	{
		if (byte & (0x80 >> ibit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		++ibit;
		write(2, ">", 1);
		pause();
	}
}

static void	ft_transmit_terminated(pid_t pid, void *buff, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		ft_transmit_byte(pid, ((t_byte *) buff)[i++]);
	ft_transmit_byte(pid, 0x00);
}

int main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;
	size_t	message_len;

	if (ac != 3)
	{
		write(2, "Error : call with './client <pid> <message>'\n", 46);
		exit(-1);
	}
	signal(SIGUSR1, ft_waky);
	// TODO replace with ft versions
	server_pid = atoi(av[1]);
	message = av[2];
	message_len = strlen(message);
	ft_transmit_terminated(server_pid, &message_len, sizeof(size_t));
	ft_transmit_terminated(server_pid, message, message_len);
	return (0);
}

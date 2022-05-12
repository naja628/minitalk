#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft.h"

void	ft_transmit_byte(pid_t pid, char byte)
{
	int	ibit;

	ibit = 0;
	while (ibit < 8)
	{
		if (byte & (0x80 >> ibit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		++ibit;
		usleep(250);
	}
}

void	ft_ntransmit_term(pid_t pid, void *buff, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		ft_transmit_byte(pid, ((char *) buff)[i++]);
	ft_transmit_byte(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;
	size_t	message_len;

	if (ac != 3)
	{
		write(2, "error : call with './client <pid> <message>'\n", 46);
		exit(-1);
	}
	server_pid = ft_atoi(av[1]);
	message = av[2];
	message_len = ft_strlen(message);
	ft_ntransmit_term(server_pid, &message_len, sizeof(size_t));
	ft_ntransmit_term(server_pid, message, message_len);
	return (0);
}

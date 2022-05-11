#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft.h"

void	ft_send_byte(pid_t pid, char byte)
{
	const int	dt_us = 2000;
	int			ibit;

	ibit = 0;
	while (ibit < 8)
	{
		if ((unsigned char) byte & (0x80 >> ibit))
			kill(pid, SIGUSR2);
		else 
			kill(pid, SIGUSR1);
		++ibit;
		usleep(dt_us);
	}
}

void	ft_send_message(pid_t pid, char *message)
{
	while (*message)
		ft_send_byte(pid, *(message++));
	ft_send_byte(pid, '\0');
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("usage: client <pid> <message>\n", 2);
		return (1);
	}
	ft_send_message(ft_atoi(av[1]), av[2]);
	return (0);
}

#include <signal.h>
#include "libft.h"
#include "sender_bonus.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("usage: client <pid> <message>\n", 2);
		return (1);
	}
	signal(SIGUSR1, ft_send_bit_plus);
	ft_send_message(ft_atoi(av[1]), av[2]);
	return (0);
}

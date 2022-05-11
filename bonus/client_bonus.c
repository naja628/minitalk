#include <signal.h>
#include <sys/types.h>
#include "libft.h"
#include "sender_bonus.h"
int	main(int ac, char **av)
{
	pid_t	server_pid;
	struct sigaction	act;

	server_pid = ft_atoi(av[1]);
	if (server_pid == 0)
		ft_putstr_fd("Error: first argument must be a pid\n", 2);
	if (ac != 3)
	{
		ft_putstr_fd("Error; call with: client <pid> <message>\n", 2);
		return (1);
	}
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	act.sa_flags = 0;
	act.sa_handler = ft_send_bit_plus;
	sigaction(SIGUSR1, &act, NULL);
	ft_send_message(server_pid, av[2]);
	return (0);
}

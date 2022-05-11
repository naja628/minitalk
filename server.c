#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "libft.h"

void	ft_receive_bit(int signum)
{
	static char	byte = 0x00;
	static int	ibit = 0;

	if (signum == SIGUSR2)
		byte |= ((unsigned char) 0x80 >> ibit);
	++ibit;
	if (ibit == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else 
			write(1, &byte, 1);
		ibit = 0;
		byte = 0x00;
	}
}

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, ft_receive_bit);
	signal(SIGUSR2, ft_receive_bit);
	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (1);
}


#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "ft_printf.h"
#include "message_bonus.h"

void	ft_receive_bit(int signum, siginfo_t *info, void *not_used)
{
	static int			ibit = 0;
	static t_byte		byte = 0x00;
	static t_message	message = {NULL, 0, 0};

	(void) not_used;
	kill(info->si_pid, SIGUSR1);
	if (!message.buffer)
		ft_init_message(&message);
	if (signum == SIGUSR2)
		byte |= 0x80 >> ibit;
	++ibit;
	if (ibit == 8)
	{
		if (byte == 0x00)
		{
			ft_flush_message(&message);
			write(1, "\n", 1);
		}
		else
			ft_append_byte(&message, byte);
		ibit = 0;
		byte = 0x00;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_receive_bit;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	pid = getpid();
	ft_printf("PID: %d\n", (int) pid);
	while (1)
		pause();
	return (0);
}

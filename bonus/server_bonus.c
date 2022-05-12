/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:35 by najacque          #+#    #+#             */
/*   Updated: 2022/05/12 15:39:35 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "ft_printf.h"
#include "message_bonus.h"

static pid_t	ft_last_if_zero(pid_t siginfo_pid)
{
	static pid_t	last_pid = 0;

	if (siginfo_pid)
		last_pid = siginfo_pid;
	return (last_pid);
}

void	ft_receive_bit(int signum, siginfo_t *info, void *not_used)
{
	static int			ibit = 0;
	static t_byte		byte = 0x00;
	static t_message	message = {NULL, 0, 0};

	(void) not_used;
	kill(ft_last_if_zero(info->si_pid), SIGUSR1);
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

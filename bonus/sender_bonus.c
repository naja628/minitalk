#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include "sender_bonus.h"

static t_sender	g_sender;
#include<stdio.h>

void	ft_send_bit_plus(int signum)
{
	static int	ibit = 0;

	(void) signum;
	if (!g_sender.message)
		return ;
	if ((t_byte) *(g_sender.message) & (0x80 >> ibit))
		kill(g_sender.pid, SIGUSR2);
	else
		kill(g_sender.pid, SIGUSR1);
	printf("bit: %c\n", ((t_byte) *(g_sender.message) & (0x80 >> ibit)) ?
			'1' : '0');
	++ibit;
	if (ibit == 8)
	{
		if (*g_sender.message == '\0')
			g_sender.message = NULL;
		else
			++g_sender.message;
		ibit = 0;
	}
}

void	ft_send_message(pid_t pid, char *message)
{
	const int	dt_us = 500;

	g_sender.message = message;
	g_sender.pid = pid;
	//ft_send_bit_plus(SIGUSR1);
	kill(getpid(), SIGUSR1);
	while (g_sender.message)
		usleep(dt_us);
}

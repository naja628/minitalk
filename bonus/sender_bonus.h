#ifndef SENDER_BONUS_H
# define SENDER_BONUS_H

typedef unsigned char	t_byte;

typedef struct s_sender
{
	char	*message;
	pid_t	pid;
}	t_sender;

void	ft_send_bit_plus(int signum);
void	ft_send_message(pid_t pid, char *message);

#endif

#ifndef MESSAGE_BONUS_H
# define MESSAGE_BONUS_H

typedef unsigned char	t_byte;

typedef struct s_message
{
	char	*buffer;
	size_t	i;
	size_t	sz;
}	t_message;

void	ft_init_message(t_message *m);
void	ft_append_byte(t_message *m, t_uchar byte);
void	ft_flush_message(t_message *m);

#endif

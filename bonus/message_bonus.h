/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:33 by najacque          #+#    #+#             */
/*   Updated: 2022/05/12 15:39:33 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	ft_append_byte(t_message *m, t_byte byte);
void	ft_flush_message(t_message *m);

#endif

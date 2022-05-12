/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:34 by najacque          #+#    #+#             */
/*   Updated: 2022/05/12 15:39:34 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:32 by najacque          #+#    #+#             */
/*   Updated: 2022/05/12 15:39:32 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "message_bonus.h"

void	ft_init_message(t_message *m)
{
	const int	default_sz = 32;

	m->buffer = malloc(default_sz);
	if (!m->buffer)
	{
		ft_putstr_fd("Fatal malloc error\n", 2);
		exit (-1);
	}
	m->i = 0;
	m->sz = default_sz;
}

void	ft_append_byte(t_message *m, t_uchar byte)
{
	char	*new_buff;

	if (m->i == m->sz)
	{
		new_buff = malloc(2 * m->sz);
		if (!new_buff)
		{
			free(m->buffer);
			ft_putstr_fd("Fatal malloc error\n", 2);
			exit (-1);
		}
		ft_memcpy(new_buff, m->buffer, m->sz);
		m->sz *= 2;
		free(m->buffer);
		m->buffer = new_buff;
	}
	m->buffer[m->i++] = byte;
}

void	ft_flush_message(t_message *m)
{
	write(1, m->buffer, m->i);
	free(m->buffer);
	m->buffer = NULL;
	m->i = 0;
	m->sz = 0;
}

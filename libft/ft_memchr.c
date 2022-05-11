/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:04 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:12 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uint	i;

	i = 0;
	while (i < n)
	{
		if (*((t_uchar *)s + i) == (t_uchar) c)
			return ((void *)s + i);
		++i;
	}
	return (NULL);
}

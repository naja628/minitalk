/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:05 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:13 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_uint	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*((t_uchar *)dst + i) = *((t_uchar *)src + i);
		++i;
	}
	return (dst);
}

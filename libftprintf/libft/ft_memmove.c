/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:06 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:14 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst > src)
	{
		while (n > 0)
		{
			*((t_uchar *)dst + n - 1) = *((t_uchar *)src + n - 1);
			--n;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, n));
}

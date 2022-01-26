/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:05 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:13 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	const t_uchar	*chr_p1;
	const t_uchar	*chr_p2;

	chr_p1 = p1;
	chr_p2 = p2;
	while (n != 0)
	{
		if (*chr_p1 != *chr_p2)
			return (*chr_p1 - *chr_p2);
		++chr_p1;
		++chr_p2;
		--n;
	}
	return (0);
}

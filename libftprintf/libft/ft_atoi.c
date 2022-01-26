/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:07:39 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 16:40:32 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

typedef unsigned long long	t_ull;

int	ft_atoi(const char *s)
{
	int		sign;
	t_ull	acc;

	while (('\t' <= *s && *s <= '\r') || *s == ' ')
		++s;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	acc = 0;
	while (ft_isdigit(*s))
	{
		if (acc > -(t_ull) LONG_MIN && sign == -1)
			return (0);
		if (acc > (t_ull) LONG_MAX && sign == 1)
			return (-1);
		acc *= 10;
		acc += *s - '0';
		++s;
	}
	return ((int) sign * acc);
}

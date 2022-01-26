/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:08:41 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 17:08:41 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "printf_utils.h"

int	ft_is_in(char const *set, char c)
{
	if (!set)
		return (0);
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

t_uint	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_challoc(char c)
{
	char	*out;

	out = malloc(sizeof(char));
	if (!out)
		return (NULL);
	*out = c;
	return (out);
}

static size_t	ft_num_digits(t_uint n)
{
	size_t	count;

	count = 1;
	while (n >= 10)
	{
		++count;
		n /= 10;
	}
	return (count);
}

char	*ft_uitoa(t_uint n)
{
	size_t	sz;
	char	*out;

	sz = ft_num_digits(n);
	out = malloc(sizeof(char) * (sz + 1));
	if (!out)
		return (NULL);
	out[sz] = '\0';
	if (n == 0)
		*out = '0';
	while (n)
	{
		out[--sz] = n % 10 + '0';
		n /= 10;
	}
	return (out);
}

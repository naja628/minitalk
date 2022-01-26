/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:08:35 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 17:08:35 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_hexstr.h"

/* note : size of 0 needs to be 1 */
static size_t	ft_num_sz_hex(size_t n)
{
	if (n < 16)
		return (1);
	return (1 + ft_num_sz_hex(n / 16));
}

static void	ft_hexstr_helper(char *units_place, size_t n)
{
	char	*digits;

	digits = "0123456789abcdef";
	*units_place = digits[n % 16];
	if (n >= 16)
		ft_hexstr_helper(units_place - 1, n / 16);
}

char	*ft_hexstr(size_t n)
{
	char	*s;
	size_t	sz;

	sz = ft_num_sz_hex(n);
	s = malloc(sizeof(char) * (1 + sz));
	if (!s)
		return (NULL);
	ft_hexstr_helper(s + sz - 1, n);
	s[sz] = '\0';
	return (s);
}

static void	ft_bighexstr_helper(char *units_place, size_t n)
{
	char	*digits;

	digits = "0123456789ABCDEF";
	*units_place = digits[n % 16];
	if (n >= 16)
		ft_bighexstr_helper(units_place - 1, n / 16);
}

char	*ft_bighexstr(size_t n)
{
	char	*s;
	size_t	sz;

	sz = ft_num_sz_hex(n);
	s = malloc(sizeof(char) * (1 + sz));
	if (!s)
		return (NULL);
	ft_bighexstr_helper(s + sz - 1, n);
	s[sz] = '\0';
	return (s);
}

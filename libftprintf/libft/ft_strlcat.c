/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:23 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:21 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t sz)
{
	size_t	count;

	if (!src || !dest)
		return (0);
	count = 0;
	while (count < sz && *dest)
	{
		++dest;
		++count;
	}
	if (*dest == 0)
	{
		while (count + 1 < sz && *src)
		{
			*(dest++) = *(src++);
			++count;
		}
		*dest = '\0';
	}
	while (*src)
	{
		++src;
		++count;
	}
	return (count);
}

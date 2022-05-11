/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:23 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:22 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t sz)
{
	size_t	count;

	if (!src || !dest)
		return (0);
	count = 0;
	while (count + 1 < sz && *src)
	{
		*(dest++) = *(src++);
		++count;
	}
	if (sz != 0)
		*dest = '\0';
	while (*src)
	{
		++src;
		++count;
	}
	return (count);
}

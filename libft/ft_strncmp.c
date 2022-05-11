/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:26 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:24 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (n != 0 && *s1)
	{
		if (*s1 != *s2)
			return ((t_uchar)(*s1) - (t_uchar)(*s2));
		++s1;
		++s2;
		--n;
	}
	if (n != 0)
		return ((t_uchar)(*s1) - (t_uchar)(*s2));
	else
		return (0);
}

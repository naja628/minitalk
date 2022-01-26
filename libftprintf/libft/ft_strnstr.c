/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:27 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:24 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	unsigned int	i;

	if (!s || !to_find)
		return ((char *) s);
	if (*to_find == '\0')
		return ((char *) s);
	while (*s && n > 0 && *to_find != *s)
	{
		--n;
		++s;
	}
	if (*s == '\0' || n == 0)
		return (NULL);
	i = 1;
	while (s[i] && to_find[i] && n - i > 0 && to_find[i] == s[i])
		++i;
	if (to_find[i] == '\0')
		return ((char *) s);
	else
		return (ft_strnstr(s + 1, to_find, n - 1));
}

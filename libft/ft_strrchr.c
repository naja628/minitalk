/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:28 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:25 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_instance;

	if (!s)
		return (NULL);
	last_instance = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last_instance = (char *) s;
		++s;
	}
	if ((char) c == '\0')
		last_instance = (char *) s;
	return (last_instance);
}

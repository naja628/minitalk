/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:25 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 14:06:49 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*image;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	image = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!image)
		return (NULL);
	i = 0;
	while (s[i])
	{
		image[i] = f(i, s[i]);
		++i;
	}
	image[i] = '\0';
	return (image);
}

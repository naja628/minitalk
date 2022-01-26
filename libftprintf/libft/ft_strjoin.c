/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:22 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 14:02:00 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* note : using strlact makes us pass unnecessarily through 
 * s1 twice, but this seems pretty minor */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	sz;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	sz = ft_strlen(s1) + ft_strlen(s2) + 1;
	concat = malloc(sizeof(char) * sz);
	if (!concat)
		return (NULL);
	ft_strlcpy(concat, s1, sz);
	ft_strlcat(concat, s2, sz);
	return (concat);
}

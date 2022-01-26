/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:23:47 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 14:19:31 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

typedef unsigned int	t_uint;

static size_t	ft_nwords(char const *s, char c)
{
	size_t	nwords;

	nwords = 0;
	if (*s == '\0')
		return (nwords);
	if (*s != c)
		nwords = 1;
	while (*(++s))
	{
		if (*s != c && *(s - 1) == c)
			++nwords;
	}
	return (nwords);
}

static char	*ft_stream_create_word(char const **stream, char c)
{
	size_t	i;
	char	*word;

	while (**stream && **stream == c)
		++(*stream);
	if (**stream == '\0')
		return (NULL);
	i = 0;
	while ((*stream)[i] && *(*stream + i) != c)
		++i;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (**stream && **stream != c)
		word[i++] = *((*stream)++);
	word[i] = '\0';
	return (word);
}

static void	ft_free_tab(char **tab)
{
	char	**pos;

	if (tab == NULL)
		return ;
	pos = tab;
	while (*pos != NULL)
		free(*(pos++));
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nwords;
	t_uint	i;

	if (s == NULL)
		return (NULL);
	nwords = ft_nwords(s, c);
	tab = malloc(sizeof(char *) * (nwords + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		tab[i] = ft_stream_create_word(&s, c);
		if (!tab[i])
		{
			ft_free_tab(tab);
			return (NULL);
		}
		++i;
	}
	tab[i] = NULL;
	return (tab);
}

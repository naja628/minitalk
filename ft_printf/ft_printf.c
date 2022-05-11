/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:08:40 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 17:08:40 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_format_one.h"
#include "definitions.h"
#include "printf_utils.h"
#include "ft_printf.h"

static int	ft_printf_helper(char const *s, va_list va)
{
	size_t	i;
	int		j;
	char	spec;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '%')
		++i;
	write(1, s, i);
	if (!s[i])
		return (i);
	s += i + 1;
	j = ft_format_one(s, &spec, va);
	if (j == -1)
		return (-1);
	i += j;
	while (*s && *s != spec)
		++s;
	return (i + ft_printf_helper(s + 1, va));
}

int	ft_printf(char const *s, ...)
{
	int		ret;
	va_list	to_format;

	if (s == NULL)
		return (-1);
	va_start(to_format, s);
	ret = ft_printf_helper(s, to_format);
	va_end(to_format);
	return (ret);
}

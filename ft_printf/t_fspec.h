/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fspec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:37:08 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 18:37:08 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FSPEC_H
# define T_FSPEC_H

# include <stddef.h>
# include "definitions.h"

/* fspec : format specifier
 * spec is the specifier character (i, d etc)
 * slen is the len of the format specifier (% excluded)
 * negative width means width means unspecified */
typedef struct s_fspec
{
	char		flags[NFLAGS + 1];
	ptrdiff_t	width;
	t_uint		precision;
	char		spec;
}	t_fspec;

/* take what comes after a % in a format string 
 * (eg "+5.2d...")
 * and make a t_fspec out of it */
void	ft_parse_spec(char const *s, t_fspec *f);

#endif

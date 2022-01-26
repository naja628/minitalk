/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sarg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:37:10 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 18:37:10 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SARG_H
# define T_SARG_H
# include <stdarg.h>

/* sarg type : pieces to build a String out of an ARGument
 * u prefix means not necessarily terminated (Unterminated)
 * (hence the need for a len)
 * this is so we can output '\0' without too much
 * trouble and to avoid some unnecessary copying 
 */
typedef struct s_sarg
{
	char	*ubasic;
	size_t	base_len;
	char	*prefix;
	char	*upad;
	size_t	pad_len;
}	t_sarg;

/* if terminated len is ignored and strlen is used instead */
void	ft_set_basic(t_sarg *a, char *ubasic, int terminated, size_t len);

/* consume 1 arg and convert it to a t_sarg 
 * ignoring flags.
 *
 * % is handled elsewhere (as it doesn't consume an arg).
 * 
 * num_arg is useful for the d/i case where the conversion is
 * a bit tricky due to signedness.
 * 
 * errors are indicated by a->ubasic being NULL upon exit */
void	ft_basic_ofarg(t_sarg *a, char spec, va_list args);

#endif

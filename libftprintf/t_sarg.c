/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:08:44 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 17:08:44 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_utils.h"
#include "t_sarg.h"
#include "ft_hexstr.h"

/* if terminated len is ignored and strlen is used instead */
void	ft_set_basic(t_sarg *a, char *ubasic, int terminated, size_t len)
{
	a->ubasic = ubasic;
	if (terminated)
		a->base_len = ft_strlen(ubasic);
	else
		a->base_len = len;
}

/* wrapper around strdup that handles the case 
 * where s is NULL 
 * we make sure ubasic is terminated so 
 * handle_precision doesn't complain 
 * (ideally this should be refactored) */
static void	ft_strdup_wrapper(t_sarg *a, char const *s)
{
	if (!s)
		ft_set_basic(a, ft_strdup("(null)"), 1, 0);
	else
		ft_set_basic(a, ft_strdup(s), 1, 0);
}

/* consume 1 arg and convert it to a t_sarg 
 * ignoring flags.
 *
 * % is handled elsewhere (as it doesn't consume an arg).
 * 
 * num_arg is useful for the d/i case where the conversion is
 * a bit tricky due to signedness.
 * 
 * errors are indicated by a->ubasic being NULL upon exit */
void	ft_basic_ofarg(t_sarg *a, char spec, va_list args)
{
	int	num_arg;

	if (spec == 'd' || spec == 'i')
	{
		num_arg = va_arg(args, int);
		if (num_arg < 0)
			a->prefix = "-";
		ft_set_basic(a, ft_uitoa(ft_abs(num_arg)), 1, 0);
	}
	else if (spec == 'u')
		ft_set_basic(a, ft_uitoa(va_arg(args, t_uint)), 1, 0);
	else if (spec == 'x')
		ft_set_basic(a, ft_hexstr(va_arg(args, t_uint)), 1, 0);
	else if (spec == 'X')
		ft_set_basic(a, ft_bighexstr(va_arg(args, t_uint)), 1, 0);
	else if (spec == 'p')
		ft_set_basic(a, ft_hexstr((size_t) va_arg(args, void *)), 1, 0);
	else if (spec == 'c')
		ft_set_basic(a, ft_challoc(va_arg(args, int)), 0, 1);
	else if (spec == 's')
		ft_strdup_wrapper(a, va_arg(args, char *));
}

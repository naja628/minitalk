/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:37:07 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 18:37:07 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H

typedef unsigned int	t_uint;

int		ft_is_in(char const *set, char c);
t_uint	ft_abs(int n);
char	*ft_challoc(char c);
char	*ft_uitoa(t_uint n);

#endif

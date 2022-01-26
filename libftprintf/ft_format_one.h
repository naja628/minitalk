/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_one.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:36:58 by najacque          #+#    #+#             */
/*   Updated: 2021/11/15 18:36:58 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_ONE_H
# define FT_FORMAT_ONE_H

/* prints 1 arg (or %), and return len of output string 
 * if pb do nothing and return -1 */
int	ft_format_one(char const *s, char *spec, va_list va);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:59:02 by najacque          #+#    #+#             */
/*   Updated: 2021/10/16 13:47:16 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

typedef unsigned int	t_uint;

void	ft_putchar_fd(char c, int fd);

static t_uint	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static void	ft_putnbr_helper(t_uint n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_helper(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	t_uint	abs;

	abs = ft_abs(n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_helper(abs, fd);
}

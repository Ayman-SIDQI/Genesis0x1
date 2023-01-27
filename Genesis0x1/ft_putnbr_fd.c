/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:59:25 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 14:04:58 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	o;

	o = n;
	if (o < 0)
	{
		o = o * (-1);
		ft_putchar_fd('-', fd);
	}
	if (o <= 9 && o >= 0)
		ft_putchar_fd(o + 48, fd);
	else
	{
		ft_putnbr_fd(o / 10, fd);
		ft_putnbr_fd(o % 10, fd);
	}
}

void	ktbn(int n)
{
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

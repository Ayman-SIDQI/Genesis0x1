/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:49:19 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/22 15:04:43 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	sprite_dance(short exity, short exitx, t_map *all)
{
	static int	anima;

	anima++;
	if (anima == 1000)
		putblk(all, exitx, exity, all->exit);
	else if (anima == 3500 && all->splitted[exity][exitx] != 'P')
		putblk(all, exitx, exity, all->portal2);
	else if (anima == 6000 && all->splitted[exity][exitx] != 'P')
		putblk(all, exitx, exity, all->portal3);
	else if (anima == 8500 && all->splitted[exity][exitx] != 'P')
		putblk(all, exitx, exity, all->portal4);
	else if (anima > 8500 && all->splitted[exity][exitx] != 'P')
		anima = 0;
}

void	incrementor(t_map *all, int n)
{
	putblk(all, 0, 0, all->tiles);
	mlx_string_put(all->mlx_ptr, all->mlx_win, 0, 0, 0xFFFFFF, ft_itoa(n));
}

//mochkil mdyal invalid and segfault maybe from coordinate dyal enemy
//it doesnt change with enemy

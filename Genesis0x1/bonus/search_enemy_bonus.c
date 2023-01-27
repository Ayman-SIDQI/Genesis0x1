/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:12:12 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/23 17:03:40 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	search_enemy(t_map *all)
{
	int	i;
	int	o;

	o = 0;
	while (all->splitted[o] && all->y != 0)
	{
		i = 0;
		while (all->splitted[o][i])
		{
			if (all->splitted[o][i] == 'Y' && all->y >= 1)
			{
				all->enemyx = i;
				all->enemyy = o;
				return (1);
			}
			i++;
		}
		o++;
	}
	return (0);
}

// int	enemy_coors(int number_enem, char *str, t_map *all)
// {
// 	int	i;

// 	i = -1;
// 	all->y = 0;
// 	while (str[++i])
// 	{
// 		if (str[i] == 'Y')
// 	}
// 	return (y);
// }
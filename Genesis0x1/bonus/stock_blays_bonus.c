/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_blays_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:05:48 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/23 17:03:57 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	stock_blays(t_map *all)
{
	int	i;
	int	j;

	j = 0;
	search_enemy(all);
	while (all->splitted[j] != NULL)
	{
		i = 0;
		while (all->splitted[j][i] != '\0')
		{
			if (all->splitted[j][i] == 'P')
			{
				all->playerx = i;
				all->playery = j;
			}
			else if (all->splitted[j][i] == 'E')
			{
				all->exitx = i;
				all->exity = j;
			}
			i++;
		}
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_blays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:17:51 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/17 16:06:52 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	stock_blays(t_map *all)
{
	int	i;
	int	j;

	j = 0;
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

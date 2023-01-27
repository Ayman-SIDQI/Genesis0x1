/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_jutsu_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:38:47 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 14:13:14 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static void	enemy_move_up(t_map *all)
{
	if (all->splitted[all->enemyy - 1][all->enemyx] == '0')
	{
		putblk(all, all->enemyx, all->enemyy, all->free);
		putblk(all, all->enemyx, all->enemyy - 1, all->enemy);
		all->splitted[all->enemyy][all->enemyx] = '0';
		all->splitted[all->enemyy - 1][all->enemyx] = 'Y';
		all->enemyy = all->enemyy - 1;
	}
	else if (all->splitted[all->enemyy - 1][all->enemyx] == \
	all->splitted[all->playery][all->playerx])
	{
		var_free(all->full, all->tmp, all->splitted, NULL);
		mlx_destroy_window(all->mlx_ptr, all->mlx_win);
		free(all->mlx_ptr);
		exit(0);
	}
}

static void	enemy_move_left(t_map *all)
{
	if (all->splitted[all->enemyy][all->enemyx - 1] == '0')
	{
		putblk(all, all->enemyx, all->enemyy, all->free);
		putblk(all, all->enemyx - 1, all->enemyy, all->enemy);
		all->splitted[all->enemyy][all->enemyx] = '0';
		all->splitted[all->enemyy][all->enemyx - 1] = 'Y';
		all->enemyx = all->enemyx - 1;
	}
	else if (all->splitted[all->enemyy][all->enemyx - 1] == \
	all->splitted[all->playery][all->playerx])
	{
		var_free(all->full, all->tmp, all->splitted, NULL);
		mlx_destroy_window(all->mlx_ptr, all->mlx_win);
		free(all->mlx_ptr);
		exit(0);
	}
}

static void	enemy_move_down(t_map *all)
{
	if (all->splitted[all->enemyy + 1][all->enemyx] == '0')
	{
		putblk(all, all->enemyx, all->enemyy, all->free);
		putblk(all, all->enemyx, all->enemyy + 1, all->enemy);
		all->splitted[all->enemyy][all->enemyx] = '0';
		all->splitted[all->enemyy + 1][all->enemyx] = 'Y';
		all->enemyy = all->enemyy + 1;
	}
	else if (all->splitted[all->enemyy + 1][all->enemyx] == \
	all->splitted[all->playery][all->playerx])
	{
		var_free(all->full, all->tmp, all->splitted, NULL);
		mlx_destroy_window(all->mlx_ptr, all->mlx_win);
		free(all->mlx_ptr);
		exit(0);
	}
}

static void	enemy_move_right(t_map *all)
{
	if (all->splitted[all->enemyy][all->enemyx + 1] == '0')
	{
		putblk(all, all->enemyx, all->enemyy, all->free);
		putblk(all, all->enemyx + 1, all->enemyy, all->enemy);
		all->splitted[all->enemyy][all->enemyx] = '0';
		all->splitted[all->enemyy][all->enemyx + 1] = 'Y';
		all->enemyx = all->enemyx + 1;
	}
	else if (all->splitted[all->enemyy][all->enemyx + 1] == \
	all->splitted[all->playery][all->playerx])
	{
		var_free(all->full, all->tmp, all->splitted, NULL);
		mlx_destroy_window(all->mlx_ptr, all->mlx_win);
		free(all->mlx_ptr);
		exit(0);
	}
}

int	animation_jutsu(t_map *all)
{
	static int	enem;

	srand(time(0));
	enem++;
	if (enem > 1000)
	{
		if (rand() % 4 == 0)
			enemy_move_up(all);
		else if (rand() % 4 == 1)
			enemy_move_left(all);
		else if (rand() % 4 == 2)
			enemy_move_down(all);
		else if (rand() % 4 == 3)
			enemy_move_right(all);
		enem = 0;
	}
	sprite_dance(all->exity, all->exitx, all);
	return (0);
}

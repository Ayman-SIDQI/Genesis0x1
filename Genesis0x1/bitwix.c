/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:12:20 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/27 12:12:25 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	putblk(t_map *all, int i, int j, void *img)
{
	mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, \
	img, i * 90, j * 90);
}

void	putmap(t_map *all)
{
	all->o = 0;
	all->z = -1;
	while (all->splitted[++all->z])
	{
		all->o = 0;
		while (all->splitted[all->z][all->o] != '\0')
		{
			if (all->splitted[all->z][all->o] == '1')
				putblk(all, all->o, all->z, all->tiles);
			else if (all->splitted[all->z][all->o] == '0')
				putblk(all, all->o, all->z, all->free);
			else if (all->splitted[all->z][all->o] == 'P')
			{
				putblk(all, all->o, all->z, all->free);
				putblk(all, all->o, all->z, all->standing);
			}
			else if (all->splitted[all->z][all->o] == 'E')
				putblk(all, all->o, all->z, all->exit);
			else if (all->splitted[all->z][all->o] == 'C')
				putblk(all, all->o, all->z, all->coin);
			all->o++;
		}
	}
}

void	susume(t_map *all, int y, int x, void *img)
{
	all->splitted[all->playery - y][all->playerx - x] = 'P';
	all->playerx = all->playerx - x;
	all->playery = all->playery - y;
	all->splitted[all->playery + y][all->playerx + x] = '0';
	putblk(all, all->playerx, all->playery, img);
	putblk(all, all->playerx + x, all->playery + y, all->free);
	if (all->splitted[all->playery][all->playerx] \
	== all->splitted[all->exity][all->exitx] && all->vars.count == 0)
	{
		write(1, "YOU WIN\n", 8);
		var_free(all->full, all->tmp, all->splitted, NULL);
		mlx_destroy_window(all->mlx_ptr, all->mlx_win);
		free(all->mlx_ptr);
		exit (0);
	}
	if (all->splitted[all->playery + y][all->playerx + x] == \
	all->splitted[all->exity][all->exitx])
	{
		all->splitted[all->exity][all->exitx] = 'E';
		putblk(all, all->exitx, all->exity, all->exit);
	}
}

int	coordinator(int button, t_map *all)
{
	static int	n;

	if (button == UP && checksafe(all, 1, 0))
	{
		susume(all, 1, 0, all->sup);
		ktbn(++n);
	}
	else if (button == DOWN && checksafe(all, -1, 0))
	{
		susume(all, -1, 0, all->standing);
		ktbn(++n);
	}
	else if (button == LEFT && checksafe(all, 0, 1))
	{
		susume(all, 0, 1, all->lisr);
		ktbn(++n);
	}
	else if (button == RIGHT && checksafe(all, 0, -1))
	{
		susume(all, 0, -1, all->limn);
		ktbn(++n);
	}
	else if (button == ESC)
		mickeymous(all);
	return (0);
}

void	bitwix(t_map *all)
{
	all->mlx_ptr = mlx_init();
	if (!all->mlx_ptr)
	{
		perror("Error\n");
		mickeymous(all);
	}
	all->mlx_win = mlx_new_window(all->mlx_ptr, \
	(all->vars.len) * 90, (all->vars.aard + 1) * 90, "Genesis0x1");
	if (!all->mlx_win)
	{
		perror("Error\n");
		mickeymous(all);
	}
	allocatedabitch(all);
	putmap(all);
	size_and_width(all);
	mlx_hook(all->mlx_win, 17, 0, mickeymous, all);
	mlx_key_hook(all->mlx_win, coordinator, all);
	mlx_loop(all->mlx_ptr);
}

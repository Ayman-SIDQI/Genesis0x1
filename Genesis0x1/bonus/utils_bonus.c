/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:16:36 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 14:16:32 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static void	portal2_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->limn);
	mlx_destroy_image(all->mlx_ptr, all->sup);
	mlx_destroy_image(all->mlx_ptr, all->lisr);
	mlx_destroy_image(all->mlx_ptr, all->standing);
	mlx_destroy_image(all->mlx_ptr, all->enemy);
	mickeymous(all);
}

static void	portal3_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->limn);
	mlx_destroy_image(all->mlx_ptr, all->sup);
	mlx_destroy_image(all->mlx_ptr, all->lisr);
	mlx_destroy_image(all->mlx_ptr, all->standing);
	mlx_destroy_image(all->mlx_ptr, all->enemy);
	mlx_destroy_image(all->mlx_ptr, all->portal2);
	mickeymous(all);
}

static void	portal4_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->limn);
	mlx_destroy_image(all->mlx_ptr, all->sup);
	mlx_destroy_image(all->mlx_ptr, all->lisr);
	mlx_destroy_image(all->mlx_ptr, all->standing);
	mlx_destroy_image(all->mlx_ptr, all->enemy);
	mlx_destroy_image(all->mlx_ptr, all->portal2);
	mlx_destroy_image(all->mlx_ptr, all->portal3);
	mickeymous(all);
}

void	portal(t_map *all)
{
	all->portal2 = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/portal2.xpm", &all->vars.width, &all->vars.height);
	if (!all->portal2)
		portal2_death (all);
	all->portal3 = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/portal3.xpm", &all->vars.width, &all->vars.height);
	if (!all->portal3)
		portal3_death (all);
	all->portal4 = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/portal4.xpm", &all->vars.width, &all->vars.height);
	if (!all->portal4)
		portal4_death (all);
}

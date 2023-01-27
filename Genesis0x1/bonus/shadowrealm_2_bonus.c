/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowrealm_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:31:39 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/25 10:53:30 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	lisr_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->limn);
	mlx_destroy_image(all->mlx_ptr, all->sup);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

void	standing_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->limn);
	mlx_destroy_image(all->mlx_ptr, all->sup);
	mlx_destroy_image(all->mlx_ptr, all->lisr);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

void	enemy_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->limn);
	mlx_destroy_image(all->mlx_ptr, all->sup);
	mlx_destroy_image(all->mlx_ptr, all->lisr);
	mlx_destroy_image(all->mlx_ptr, all->standing);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

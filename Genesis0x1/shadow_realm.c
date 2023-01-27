/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_realm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:49:10 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/25 10:51:10 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	free_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

void	coin_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

void	exit_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

void	limn_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

void	sup_death(t_map *all)
{
	mlx_destroy_image(all->mlx_ptr, all->tiles);
	mlx_destroy_image(all->mlx_ptr, all->free);
	mlx_destroy_image(all->mlx_ptr, all->coin);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->limn);
	perror("Error\n image not found.\n");
	mickeymous(all);
}

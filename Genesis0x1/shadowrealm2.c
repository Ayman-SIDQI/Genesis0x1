/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowrealm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:22:18 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/25 10:51:26 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

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

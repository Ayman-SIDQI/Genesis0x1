/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_mlxd_fp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:21:03 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 14:17:27 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	fd_mlx_fp_bonus(char *full, char *tmp, char**splitted, t_map *all)
{
	if (full)
		free(full);
	if (tmp)
		free(tmp);
	if (splitted)
		free_2d(splitted, 2);
	mlx_destroy_window(all->mlx_ptr, all->mlx_win);
	free(all->mlx_ptr);
	exit (0);
}

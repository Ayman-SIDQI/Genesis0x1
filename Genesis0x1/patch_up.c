/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:24 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/27 11:47:35 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	mickeymous(t_map *all)
{
	var_free(all->full, all->tmp, all->splitted, NULL);
	if (all->mlx_ptr && all->mlx_win)
	{
		mlx_destroy_window(all->mlx_ptr, all->mlx_win);
		free(all->mlx_ptr);
	}
	exit(1);
	return (0);
}

void	size_and_width(t_map *all)
{
	if (all->vars.len > 29 || all->vars.aard > 16)
	{
		perror("Error\nInvalid. ¯\\_(ツ)_/¯");
		mickeymous(all);
	}
}

void	last_newline(t_map *all)
{
	int	i;

	i = 0;
	while (all->full[i])
		i++;
	i--;
	if (all->full[i] == '\n')
	{
		perror("Error\nNewline achrif\n");
		var_free(all->full, all->tmp, all->splitted, NULL);
		exit(1);
	}
}

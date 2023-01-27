/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readerallocator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:22:53 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/25 10:52:55 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	norminett(t_map *all)
{
	var_free(all->full, all->tmp, NULL, NULL);
	exit_close_ciao (all->fd);
}

void	jm3str(char *av, t_map *all)
{
	int	i;

	all->full = NULL;
	i = 0;
	all->fd = open(av, O_RDONLY);
	all->tmp = get_next_line(all->fd);
	if (all->tmp == NULL)
		norminett(all);
	i = 1;
	while (all->tmp != NULL)
	{
		all->full = ft_strjoin(all->full, all->tmp);
		if (all->tmp[0] == '\n')
			norminett(all);
		free(all->tmp);
		all->tmp = get_next_line(all->fd);
		all->vars.aard = i++;
	}
	all->vars.aard--;
	free(all->tmp);
	close(all->fd);
}

void	to_becontinued(t_map *all)
{
	all->limn = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/limn.xpm", &all->vars.width, &all->vars.height);
	if (!all->limn)
		free_death(all);
	all->sup = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/sup.xpm", &all->vars.width, &all->vars.height);
	if (!all->sup)
		sup_death(all);
	all->lisr = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/lisr.xpm", &all->vars.width, &all->vars.height);
	if (!all->lisr)
		lisr_death(all);
	all->standing = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/standing.xpm", &all->vars.width, &all->vars.height);
	if (!all->standing)
		standing_death(all);
}

void	allocatedabitch(t_map *all)
{
	all->tiles = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/tiles.xpm", &all->vars.width, &all->vars.height);
	if (!all->tiles)
	{
		destroy_win_innit(all);
		exit(1);
	}
	all->free = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/free.xpm", &all->vars.width, &all->vars.height);
	if (!all->free)
		free_death(all);
	all->coin = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/coin.xpm", &all->vars.width, &all->vars.height);
	if (!all->coin)
		coin_death(all);
	all->exit = mlx_xpm_file_to_image(all->mlx_ptr, "textures/exit.xpm", \
	&all->vars.width, &all->vars.height);
	if (!all->exit)
		exit_death(all);
	to_becontinued(all);
}

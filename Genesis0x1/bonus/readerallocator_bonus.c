/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader&allocator_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:05:39 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 15:04:15 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

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
	close(all->fd);
}

void	to_becontinued(t_map *all)
{
	all->limn = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/limn.xpm", &all->vars.width, &all->vars.height);
	if (!all->limn)
		limn_death(all);
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
	all->enemy = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/enemy.xpm", &all->vars.width, &all->vars.height);
	if (!all->enemy)
		enemy_death(all);
	portal(all);
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
	all->exit = mlx_xpm_file_to_image(all->mlx_ptr, \
	"textures/portal1.xpm", &all->vars.width, &all->vars.height);
	if (!all->exit)
		exit_death(all);
	to_becontinued(all);
}

/* jm3str function is reading in a file specified by the string passed
 in as the first argument (av).
It uses the get_next_line function to read the file line by line and 
stores the entire file content into the all->full variable, which is a string.
all->vars.aard is being used to keep track of the number of lines in the file.
allocatedabitch function appears to be loading images from file into 
memory and assigning them to variables in the t_map struct.
The function uses the mlx_xpm_file_to_image function from the MiniLibX 
library to load image files in XPM format into memory and assign them to
 the corresponding variables in the all struct.
 It loads the following images:

    - tiles
    - free
    - coin
    - exit
    - standing
    These images are used later in the program for rendering the game.
    It is also worth noting that the function is not closing the file 
	descriptor fd after reading the file.
*/
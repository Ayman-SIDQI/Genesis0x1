/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:09:51 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 14:56:44 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	exit_perror(void)
{
	perror("Error\nInvalid map ¯\\_(ツ)_/¯\n");
	exit(1);
}

void	exit_close_ciao(int fd)
{
	perror("Error\nInvalid map ¯\\_(ツ)_/¯\n");
	close (fd);
	exit(1);
}

void	free_2d(char **str, short num)
{
	int	i;
	int	o;

	o = 0;
	i = 0;
	if (num == 1)
	{
		while (str[o])
			free(str[o++]);
		free(str);
	}
	else if (num == 2)
	{
		while (str[o])
			free(str[o++]);
		free(str);
	}
}

void	var_free(char *full, char *tmp, char**splitted, char **dupspl)
{
	if (full)
		free(full);
	if (tmp)
		free(tmp);
	if (dupspl)
		free_2d(dupspl, 1);
	if (splitted)
		free_2d(splitted, 2);
}

void	destroy_win_innit(t_map *all)
{
	var_free(all->full, all->tmp, all->splitted, NULL);
	mlx_destroy_window(all->mlx_ptr, all->mlx_win);
	free(all->mlx_ptr);
	perror("Error\n ¯\\_(ツ)_/¯");
}

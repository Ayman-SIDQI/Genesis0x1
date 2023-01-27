/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksafe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:04:15 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 15:08:10 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	existance_check(char	**str, t_map *all)
{
	all->checks.c = 0;
	all->checks.e = 0;
	all->checks.p = 0;
	all->checks.j = 0;
	while (str[all->checks.j])
	{
		all->checks.i = 0;
		while (str[all->checks.j][all->checks.i])
		{
			if (str[all->checks.j][all->checks.i] == 'C')
				all->checks.c++;
			else if (str[all->checks.j][all->checks.i] == 'P')
				all->checks.p++;
			else if (str[all->checks.j][all->checks.i] == 'E')
				all->checks.e++;
			all->checks.i++;
		}
		all->checks.j++;
	}
	if (all->checks.c >= 1 || all->checks.p == 1 || all->checks.e == 1)
	{
		var_free(all->full, all->tmp, all->dupspl, all->splitted);
		exit_perror();
	}
}

void	backtrack(t_map *all, int duplayerx, int duplayery)
{
	if (all->dupspl[duplayery - 1][duplayerx] != '1' && \
	all->dupspl[duplayery - 1][duplayerx] != 'Y')
	{
		all->dupspl[duplayery - 1][duplayerx] = 'Y';
		backtrack(all, duplayerx, duplayery - 1);
	}
	if (all->dupspl[duplayery][duplayerx - 1] != '1' && \
	all->dupspl[duplayery][duplayerx - 1] != 'Y')
	{
		all->dupspl[duplayery][duplayerx - 1] = 'Y';
		backtrack(all, duplayerx - 1, duplayery);
	}
	if (all->dupspl[duplayery + 1][duplayerx] != '1' && \
	all->dupspl[duplayery + 1][duplayerx] != 'Y')
	{
		all->dupspl[duplayery + 1][duplayerx] = 'Y';
		backtrack(all, duplayerx, duplayery + 1);
	}
	if (all->dupspl[duplayery][duplayerx + 1] != '1' && \
	all->dupspl[duplayery][duplayerx + 1] != 'Y')
	{
		all->dupspl[duplayery][duplayerx + 1] = 'Y';
		backtrack(all, duplayerx + 1, duplayery);
	}
}

int	checksafe(t_map *all, int y, int x)
{
	if (all->splitted[all->playery - y][all->playerx - x] == '1')
		return (0);
	if (all->splitted[all->playery - y][all->playerx - x] == 'C')
		all->vars.count--;
	if (all->splitted[all->playery - y][all->playerx - x] == 'Y')
		mickeymous(all);
	return (1);
}

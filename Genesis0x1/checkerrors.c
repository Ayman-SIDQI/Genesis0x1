/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:22:03 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/27 11:46:47 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ftnlast(char *s1, char *s2, t_map *all)
{
	int	i;

	i = 0;
	while (s1[i] == '1' && s1[i] != '\0' && s2[i] != '\0' && \
	s2[i] == '1')
		i++;
	if (i == all->vars.len && !((all->vars.len - 1) <= 1) \
	&& !((all->vars.aard) <= 1))
		return ;
	else
	{
		perror("Error\nInvalid. ¯\\_(ツ)_/¯");
		mickeymous(all);
	}
}

void	walls(char **splitted, t_map *all)
{
	int	i;

	i = 1;
	ftnlast(splitted[0], splitted[all->vars.aard], all);
	while (splitted[i])
	{
		if (splitted[i][0] != '1' || splitted[i][(all->vars.len - 1)] != '1')
		{
			perror("Error\nInvalid. ¯\\_(ツ)_/¯");
			mickeymous(all);
		}
		i++;
	}
}

void	checkdup(char *full, t_map *all)
{
	int	i;

	i = -1;
	all->c = 0;
	all->e = 0;
	all->p = 0;
	while (full[++i])
	{
		if (full[i] == 'C')
			all->c++;
		else if (full[i] == 'E')
			all->e++;
		else if (full[i] == 'P')
			all->p++;
		else if (full[i] != '1' && full[i] != '0' && full[i] != '\n')
			var_free_exit_perror(all);
	}
	all->vars.count = all->c;
	if (all->c >= 1 && all->e == 1 && all->p == 1)
		return ;
	perror("Error\nInvalid map. Must be: 1P, 1E and at least 1C");
	var_free(full, all->tmp, NULL, NULL);
	exit (1);
}

void	checkname(char *filename)
{
	int		i;
	char	*rstr;
	int		j;

	i = 0;
	j = 0;
	rstr = "reb.";
	if (!filename)
	{
		perror("Error\nwhere is the map my boi?\n");
		exit (1);
	}
	while (filename[i])
		i++;
	i--;
	while (filename[i] == rstr[j])
	{
		j++;
		i--;
	}
	if (j == 4)
		return ;
	exit_perror();
}

void	checkerrors(char *av, t_map	*all)
{
	int		i;

	i = 0;
	checkname(av);
	jm3str(av, all);
	checkdup(all->full, all);
	all->splitted = ft_split(all->full, '\n');
	all->vars.len = ft_strlen(all->splitted[0]);
	stock_blays(all);
	while (all->splitted[++i])
	{
		if (all->vars.len != ft_strlen(all->splitted[i]))
		{
			var_free(all->full, all->tmp, all->splitted, NULL);
			exit_perror();
		}
	}
	walls(all->splitted, all);
	all->duplayerx = all->playerx;
	all->duplayery = all->playery;
	all->dupspl = ft_split(all->full, '\n');
	backtrack(all, all->duplayerx, all->duplayery);
	existance_check(all->dupspl, all);
	free_2d(all->dupspl, 1);
	last_newline(all);
}

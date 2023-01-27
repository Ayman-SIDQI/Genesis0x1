/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:04:21 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 15:07:48 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

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
		exit_perror();
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
			var_free(all->full, all->tmp, NULL, all->splitted);
			exit_perror();
		}
		i++;
	}
}

void	checkdup(char *full, t_map *all)
{
	all->i = -1;
	all->c = 0;
	all->e = 0;
	all->p = 0;
	all->y = 0;
	while (full[++all->i])
	{
		if (full[all->i] == 'C')
			all->c++;
		else if (full[all->i] == 'E')
			all->e++;
		else if (full[all->i] == 'P')
			all->p++;
		else if (full[all->i] == 'Y')
			all->y++;
		else if (full[all->i] != '1' && full[all->i] != '0' && \
		full[all->i] != '\n' && full[all->i] != 'Y')
			var_free_exit_perror (all);
	}
	all->vars.count = all->c;
	if (all->c >= 1 && all->e == 1 && all->p == 1 && all->y == 1)
		return ;
	var_free_exit_perror(all);
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
		perror("Error\nWhere is the map my boi?\n");
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
			perror("Error\nInvalid map.");
			mickeymous(all);
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
/* checking for errors in a map file that is being read in.
 The functions check for various conditions on the map file 
 and exits the program with an error message 
 if any of the conditions are not met.

    1 - 'ftnlast' checks if the first and last characters of the 
	first and last rows of the map are '1'. If they are not, 
	it exits with an error message.
    2 - 'walls' checks if the first and last characters of each 
	row of the map are '1'. If they are not, it exits with an error
	 message.
    3 - 'checkdup' checks if there is at least one 'C', one 'E' and 
	one 'P' in the map. If there are not, it exits with an error message.
    4 - 'checkname' checks if the name of the map file ends in ".reb",
	 if it does not, it exits with an error message.
    5 - 'checkerrors' calls the above functions in order.
	 It also checks that all the rows of 
	 the map have the same number of characters and splits the full map
	  into an array of strings, one for each row of the map.
*/
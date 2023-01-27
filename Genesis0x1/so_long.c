/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:05:19 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/21 20:18:54 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	all;

	if (ac != 2)
		return (0);
	checkerrors(av[1], &all);
	bitwix(&all);
	free_2d(all.splitted, 2);
	return (0);
}

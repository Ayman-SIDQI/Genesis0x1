/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_free_exit_perror_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:52:02 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/23 22:44:50 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	var_free_exit_perror(t_map *all)
{
	var_free(all->full, all->tmp, NULL, NULL);
	exit_perror();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_free_exit_perror.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:17:33 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/24 13:18:55 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	var_free_exit_perror(t_map *all)
{
	var_free(all->full, all->tmp, NULL, NULL);
	exit_perror();
}

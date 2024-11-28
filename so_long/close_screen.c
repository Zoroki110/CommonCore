/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:19:06 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/28 15:20:59 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->wnd);
	ft_free_array(map->array);
	exit(EXIT_FAILURE);
	return (0);
}


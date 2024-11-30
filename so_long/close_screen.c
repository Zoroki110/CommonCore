/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:19:06 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/30 09:31:41 by trouilla         ###   ########.fr       */
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
void	ft_victory(t_map *map)
{
	map->exit = 1;
	map->move++;
	mlx_clear_window(map->mlx, map->wnd);
	mlx_string_put(map->mlx, map->wnd, map->x / 2 * IMG_PXL,
					map->y / 2 * IMG_PXL, 0xFFFF00, "VICTORY !");
	write(1, "\n", 1);
	write(1, "VICTORY !\n", 10);
}

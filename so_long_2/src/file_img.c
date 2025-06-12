/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:55:27 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 08:29:07 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_textures(t_game *g)
{
	int	size;

	size = TILE_SIZE;
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "assets/wall.xpm", &size,
			&size);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "assets/floor.xpm", &size,
			&size);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "assets/player.xpm", &size,
			&size);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "assets/exit.xpm", &size,
			&size);
	g->img_collect = mlx_xpm_file_to_image(g->mlx, "assets/collectible.xpm",
			&size, &size);
	if (!g->img_wall || !g->img_collect || !g->img_exit || !g->img_floor
		|| !g->img_player)
		return (write(2, "Error\nFailed to load textures\n", 31), 0);
	return (1);
}

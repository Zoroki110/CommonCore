/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:05:41 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:35:26 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	file_to_image(t_map *map)
{
	int	img;

	img = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx, "assets/Tiles.xpm", &img,
			&img);
	map->img.wall = mlx_xpm_file_to_image(map->mlx, "assets/wall_sprite_1.xpm",
			&img, &img);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, "assets/Exit_portal.xpm",
			&img, &img);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"assets/Potion_collectible.xpm", &img, &img);
	file_image_player(map);
	file_image_enemy(map);
}

void	file_image_player(t_map *map)
{
	int	img;

	img = IMG_PXL;
	map->img.player_down1 = mlx_xpm_file_to_image(map->mlx,
			"assets/witchKitty_walk_front.xpm", &img, &img);
	map->img.player_left1 = mlx_xpm_file_to_image(map->mlx,
			"assets/witchKitty_walk_left.xpm", &img, &img);
	map->img.player_right1 = mlx_xpm_file_to_image(map->mlx,
			"assets/witchKitty_walk_right.xpm", &img, &img);
	map->img.player_up1 = mlx_xpm_file_to_image(map->mlx,
			"assets/witchKitty_walk_back.xpm", &img, &img);
}

void	file_image_enemy(t_map *map)
{
	int	img;

	img = IMG_PXL;
	map->img.enemy1 = mlx_xpm_file_to_image(map->mlx,
			"assets/enemie_sprite_1.xpm", &img, &img);
	map->img.enemy2 = mlx_xpm_file_to_image(map->mlx,
			"assets/enemie_sprite_2.xpm", &img, &img);
}

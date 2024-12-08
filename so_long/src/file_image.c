/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:09:58 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/08 08:10:57 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	file_to_image(t_map *map)
{
	int	img;

	img = IMG_PXL;
	if (!img)
		return ;
	map->img.empty = mlx_xpm_file_to_image(map->mlx, "assets/Tiles.xpm", &img,
			&img);
	map->img.wall = mlx_xpm_file_to_image(map->mlx, "assets/wall_sprite_1.xpm",
			&img, &img);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, "assets/Exit_portal.xpm",
			&img, &img);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"assets/Potion_collectible.xpm", &img, &img);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx,
			"assets/enemie_sprite_1.xpm", &img, &img);
	if (map->img.empty == 0 || map->img.collectible == 0 
		|| map->img.exit == 0|| map->img.wall == 0 || map->img.enemy == 0)
		return ;
	file_image_player(map);
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
	if (map->img.player_down1 == 0 || map->img.player_right1 == 0 ||
			map->img.player_left1 == 0 || map->img.player_up1 == 0)
		return ;
}

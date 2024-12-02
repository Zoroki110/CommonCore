/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:00:25 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/02 20:15:56 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	found_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
	return (0);
}

int	key_move(int key, t_map *map)
{
	found_player(map);
	if (key == ESC)
		return (ft_close(map));
	else if (map->exit == 1)
		return (0);
	else if (key == UP || key == W)
		go_up(map);
	else if (key == DOWN || key == S)
		go_down(map);
	else if (key == RIGHT || key == D)
		go_right(map);
	else if (key == LEFT || key == A)
		go_left(map);
	else
		return (0);
	return (0);
}

int	go_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move_check1(map, x, y, RIGHT);
		move_check2(map, x, y, D);
		if (map->array[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right1, x
			* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_move(map);
	}
	map->player.x = x;
	return (0);
}

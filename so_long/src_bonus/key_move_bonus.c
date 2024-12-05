/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:06:21 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:39:52 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	found_exit(t_map *map)
{
	map->t.y = 0;
	map->t.x = 0;
	while (map->t.y < map->y)
	{
		while (map->t.x < map->x)
		{
			if (map->array[map->t.y][map->t.x] == 'E')
				break ;
			map->t.x++;
		}
		if (map->array[map->t.y][map->t.x] == 'E')
			break ;
		map->t.x = 0;
		map->t.y++;
	}
	return (0);
}

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
		map->move++;
		if (map->array[y][x] == map->array[map->t.y][map->t.x])
			ee(map, x, y);
		else
			mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x
				* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
		eeee_r(map, x, y);
		if (map->array[map->t.y][map->t.x] != 'E' && map->array[y][x] != 'P')
			map->array[map->t.y][map->t.x] = 'E';
		map->array[y][x] = 'P';
		print_move(map);
	}
	map->player.x = x;
	return (0);
}

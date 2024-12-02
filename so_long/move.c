/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:55:00 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/02 20:16:56 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_check1(t_map *map, int x, int y, int key)
{
	if (key == RIGHT)
		x += 1;
	if (key == LEFT)
		x -= 1;
	if (key == UP)
		y -= 1;
	if (key == DOWN)
		y += 1;
	if (map->array[y][x] == 'C')
	{
		map->array[y][x] = '0';
		map->c--;
	}
	if (map->array[y][x] == 'E' && map->c == 0)
		return (ft_victory(map));
}

void	move_check2(t_map *map, int x, int y, int key2)
{
	if (key2 == D)
		x += 1;
	if (key2 == A)
		x -= 1;
	if (key2 == W)
		y -= 1;
	if (key2 == S)
		y += 1;
	if (map->array[y][x] == 'C')
	{
		map->array[y][x] = '0';
		map->c--;
	}
	if (map->array[y][x] == 'E' && map->c == 0)
		return (ft_victory(map));
}

int	go_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x - 1] != '1')
	{
		move_check1(map, x, y, LEFT);
		move_check2(map, x, y, A);
		if (map->array[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left1, x
			* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_move(map);
	}
	map->player.x = x;
	return (0);
}

int	go_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->array[y - 1][x] != '1')
	{
		move_check1(map, x, y, UP);
		move_check2(map, x, y, W);
		if (map->array[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up1, x
			* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_move(map);
	}
	map->player.y = y;
	return (0);
}

int	go_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->array[y + 1][x] != '1')
	{
		move_check1(map, x, y, DOWN);
		move_check2(map, x, y, S);
		if (map->array[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x
			* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_move(map);
	}
	map->player.y = y;
	return (0);
}

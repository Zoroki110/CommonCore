/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:06:46 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:40:33 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (map->array[y][x] == 'D')
		return (ft_defeat(map));
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
		map->move++;
		if (map->array[y][x] == map->array[map->t.y][map->t.x])
			ee(map, x, y);
		else
			mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x
				* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
		eeee_l(map, x, y);
		if (map->array[map->t.y][map->t.x] != 'E')
			map->array[map->t.y][map->t.x] = 'E';
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
		map->move++;
		if (map->array[y][x] == map->array[map->t.y][map->t.x])
			ee(map, x, y);
		else
			mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x
				* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
		eeee_u(map, x, y);
		if (map->array[map->t.y][map->t.x] != 'E' && map->array[y][x] != 'P')
			map->array[map->t.y][map->t.x] = 'E';
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
		map->move++;
		if (map->array[y][x] == map->array[map->t.y][map->t.x])
			ee(map, x, y);
		else
			mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x
				* IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
		eeee_d(map, x, y);
		if (map->array[map->t.y][map->t.x] != 'E' && map->array[y][x] != 'P')
			map->array[map->t.y][map->t.x] = 'E';
		map->array[y][x] = 'P';
		print_move(map);
	}
	map->player.y = y;
	return (0);
}

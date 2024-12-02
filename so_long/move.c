/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:55:00 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/02 15:07:57 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_check(t_map *map, int x, int y, int key, int key2)
{
    if (key == RIGHT || key2 == D)
        x += 1;
    if (key == LEFT || key2 == A)
        x -= 1;
    if (key == UP || key2 == W)
        y -= 1;
    if (key == DOWN || key2 == S)
        y += 1;
    if (map->array[y][x] == 'C')
    {
        map->array[y][x] = '0';
        map->c--;
    }
    if (map->array[y][x] == 'E' && map->c == 0)
            return (ft_victory(map));
}

int	go_right(t_map *map)
{
    int x;
    int y;
    
    x = map->player.x;
    y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move_check(map, x, y, RIGHT, D);
		if (map->array[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x *IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd,
				map->img.player_right1, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		/*Fonction print_movement*/
	}
	map->player.x = x;
	return (0);
}
int	go_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x - 1] != '1')
	{
		move_check(map, x, y, LEFT, A);
		if (map->array[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.player_left1, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		/*Fonction print movement*/
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
		move_check(map, x, y, UP, W);
		if (map->array[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.player_up1, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		/*Fonction print movement*/
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
		move_check(map, x, y, DOWN, S);
		if (map->array[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des Collectibles\n", 23));
		map->move++;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.empty, x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd,
					map->img.player_down1, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		/*Fonction print movement*/
	}
	map->player.y = y;
	return (0);
}
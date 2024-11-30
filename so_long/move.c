/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:55:00 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/30 12:11:43 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_check(t_map *map, int x, int y, int key)
{
    /* if (key -> + 1 ou <- - 1 ou down + 1 ou up + 1) */
    if (key == RIGHT)
        x += 1;
    if (key == LEFT)
        x -= 1;
    if (key == UP)
        y -= 1;
    if (key == DOWN)
        y += 1;
    if (map->array[y][x] == 'E' && map->c == 0)
            return (ft_victory(map));
    if (map->array[y][x] == 'C')
    {
        map->array[y][x] = '0';
        map->c--;
    }
}

int	go_right(t_map *map)
{
    int x;
    int y;
    
    x = map->player.x;
    y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move_check(map, x, y, RIGHT);
	    if (map->array[y][x] == 'E' && (map->c != 0 || map->exit == 1))
	        return (write(1, "Reste des collectibles a avoir !\n", 33));
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
		move_check(map, x, y, LEFT);
		if (map->array[y][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des collectibles a avoir !\n", 33));
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
		move_check(map, x, y, UP);
		if (map->array[y][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des collectibles a avoir !\n", 33));
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
	if (y < map->y && map->array[y - 1][x] != 1)
	{
		move_check(map, x, y, DOWN);
		if (map->array[y][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (write(1, "Reste des collectibles a avoir !\n", 33));
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
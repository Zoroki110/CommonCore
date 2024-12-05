/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_e_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:15:18 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:40:42 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ee(t_map *map, int x, int y)
{
	if (map->array[y][x] == map->array[map->t.y][map->t.x])
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x * IMG_PXL,
			y * IMG_PXL);
	}
	if (map->array[y][x] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x
			* IMG_PXL, y * IMG_PXL);
	}
}

void	eeee_r(t_map *map, int x, int y)
{
	if (map->array[y][x] == 'E')
		ee(map, x, y);
	else
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right1, x
			* IMG_PXL, y * IMG_PXL);
	}
}

void	eeee_l(t_map *map, int x, int y)
{
	if (map->array[y][x] == 'E')
		ee(map, x, y);
	else
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left1, x
			* IMG_PXL, y * IMG_PXL);
	}
}

void	eeee_d(t_map *map, int x, int y)
{
	if (map->array[y][x] == 'E')
		ee(map, x, y);
	else
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x
			* IMG_PXL, y * IMG_PXL);
	}
}

void	eeee_u(t_map *map, int x, int y)
{
	if (map->array[y][x] == 'E')
		ee(map, x, y);
	else
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL,
			y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x
			* IMG_PXL, y * IMG_PXL);
	}
}

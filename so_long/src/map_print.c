/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:59:22 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/03 09:22:40 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_to_print(t_map *map, int x, int y)
{
	int	item;

	item = map->array[y / IMG_PXL][x / IMG_PXL];
	if (item == 'C')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.collectible, x, y);
	else if (item == '1')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
	else if (item == 'P')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x,
			y);
	else if (item == 'E')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
}

void	map_printer(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x
				* IMG_PXL, y * IMG_PXL);
			put_to_print(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		y++;
	}
}

void	print_move(t_map *map)
{
	char	*move;

	move = ft_itoa(map->move);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, " ", 1);
	write(1, "Mouvement\n", 10);
	write(1, "\x1b[33;01m", 9);
	free(move);
}

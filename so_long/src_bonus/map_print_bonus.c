/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:06:32 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:33:58 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (item == 'D')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy1, x, y);
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
	mlx_clear_window(map->mlx, map->wnd);
	map_printer(map);
	mlx_string_put(map->mlx, map->wnd, 0.8 * 50, 0.8 * 50, 0x00FF00, move);
	write(1, move, ft_strlen(move));
	write(1, " ", 1);
	write(1, "Mouvement\n", 10);
	write(1, "\x1b[33;01m", 9);
	free(move);
}

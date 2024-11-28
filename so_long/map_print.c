/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:59:22 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/28 19:47:01 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void put_to_print(t_map *map, int x, int y)
{
    int item;

    item = map->array[y / IMG_PXL][x / IMG_PXL];
    if (item == 'C' || item == 'E' || item == 'P' || item == '0' || item == '1')
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x, y);
    if (item == 'C')
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.collectible, x, y);
    else if ('1')
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
    else if ('P')
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x + 8, y);
    else if ('E')
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
}

void    map_printer(t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < map->y)
    {
        while (x < map->x)
        {
            put_to_print(map, x * IMG_PXL, y * IMG_PXL);
            x++;
        }
        x = 0;
        y++;
    }
}
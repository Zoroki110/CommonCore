/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:00:25 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/30 09:31:24 by trouilla         ###   ########.fr       */
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
	else if (key == UP)
		go_up(map);
	else if (key == DOWN)
		go_down(map);
	else if (key == RIGHT)
		go_right(map);
	else if (key == LEFT)
		go_left(map);
	else
		return (0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:00:25 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/28 19:53:56 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	found_player(t_map *map)
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
}
int	key_move(int key, t_map *map)
{
	found_player(map);
	if (key == ESC)
		return (ft_close(map));
	else if (map->exit == 1)
		return (0);
	else if (key == UP)
		up(map);
	else if (key == DOWN)
		down(map);
	else if (key == RIGHT)
		right(map);
	else if (key == LEFT)
		left(map);
	else
		return (0);
}
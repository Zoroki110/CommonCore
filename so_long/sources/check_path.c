/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:41:45 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/25 18:04:28 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_on_path(int x, int y, t_map *map)
{
	char	box;

	box = map->copy[y][x];
	if (box == 'C')
	{
		map->check_c -= 1;
		map->copy[y][x] = 'V';
	}
	else if (box == 'E')
	{
		map->check_e -= 1;
		map->copy[y][x] = 'V';
	}
	else if (box == '0' || box == 'P')
		map->copy[y][x] = 'V';
	else
		return ;
	move_on_path(x + 1, y, map);
	move_on_path(x - 1, y, map);
	move_on_path(x, y + 1, map);
	move_on_path(x, y - 1, map);
}

void	check_path(t_map *map)
{
	map->check_c = map->c;
	map->check_e = map->e;
	found_player(map);
	move_on_path(map->player.x, map->player.y, map);
	if (map->check_c != 0 || map->check_e >= map->e)
	{
		write(2, "ERROR, NO VALID PATH\n", 21);
		ft_free_array(map->array, map->y);
		ft_free_array(map->copy, map->y);
		exit(EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:41:45 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/28 13:51:10 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_on_path(int x, int y, t_map *map)
{
	char	box;

	box = map->copy[y][x];
	if (box == 'E')
	{
		map->check_e -= 1;
		map->copy[y][x] = 'V';
	}
	if (box == '1')
		return (0);
	if (box == 'E' || box == 'C' || box == 'P'
		|| box == '0')
	{
		if (box == 'C')
			map->check_c -= 1;
		map->copy[y][x] = '1';
	}
	move_on_path(x + 1, y, map);
	move_on_path(x - 1, y, map);
	move_on_path(x, y + 1, map);
	move_on_path(x, y - 1, map);
	if (map->check_e == 0 && map->check_c == 0)
		return (1);
	return (0);
}

void	check_path(t_map *map)
{
	map->check_c = map->c;
	map->check_e = map->e;
	found_player(map);
	if (move_on_path(map->player.x, map->player.y,
		map) == 0)
	{
		write(2, "ERROR, NO VALID PATH\n", 21);
		ft_free_array(map->array);
		ft_free_array(map->copy);
		exit(EXIT_FAILURE);
	}
}

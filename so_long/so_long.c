/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:29 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/26 14:53:09 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map, char **av)
{
	map->filename = av[1];
	map->player.y = 0;
	map->player.x = 0;
	map->y = 0;
	map->x = 0;
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->exit = 0;
	map->move = 0;
	map->check_c = 0;
	map->check_e = 0;
}

int	main(int ac, char **av)
{
	t_map	map;
	
	if (ac == 2)
	{
		map_init(&map, av);
		map_check(&map);
	}
}

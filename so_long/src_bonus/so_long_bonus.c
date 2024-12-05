/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:07:03 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 11:46:49 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	map->d = 0;
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
		map.mlx = mlx_init();
		map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL, map.y * IMG_PXL,
				WND_NAME);
		found_exit(&map);
		file_to_image(&map);
		map_printer(&map);
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		mlx_key_hook(map.wnd, key_move, &map);
		mlx_loop(map.mlx);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:05:17 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:35:04 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->wnd);
	ft_free_array(map->array);
	exit(EXIT_FAILURE);
	return (0);
}

void	ft_victory(t_map *map)
{
	map->exit = 1;
	map->move++;
	mlx_clear_window(map->mlx, map->wnd);
	write(1, "\n", 1);
	write(1, "VICTORY !\n", 10);
	ft_close(map);
}

void	ft_defeat(t_map *map)
{
	map->move++;
	mlx_clear_window(map->mlx, map->wnd);
	write(1, "\n", 1);
	write(1, "The enemy Kill You\n", 19);
	write(1, "TRY AGAIN IF YOU HAVE THE COURAGE\n", 34);
	ft_close(map);
}

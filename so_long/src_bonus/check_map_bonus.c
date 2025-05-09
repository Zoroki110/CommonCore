/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:04:53 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:32:19 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	check_file(t_map *map)
{
	int	len;

	len = ft_strlen2(map->filename);
	if (map->filename[len - 1] != 'r')
		error_filename();
	if (map->filename[len - 2] != 'e')
		error_filename();
	if (map->filename[len - 3] != 'b')
		error_filename();
	if (map->filename[len - 4] != '.')
		error_filename();
	if (!ft_strnstr(map->filename, ".ber", ft_strlen2(map->filename)))
		error_filename();
}

static void	check_size(t_map *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen2(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen2(map->array[y]);
		if (max != x || x == 0 || max == 0)
			error_size(map);
		y++;
	}
	map->x = max;
}

static void	check_wall(t_map *map)
{
	int	y;
	int	x;

	if (map->array[0] == NULL)
		error_size(map);
	x = 0;
	while (x < map->x && map->array[0][x] == '1')
		x++;
	if (x != map->x)
		error_wall(map);
	y = 1;
	while (y < map->y)
	{
		if (map->array[y] == NULL || map->array[y][0] != '1'
			|| map->array[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (map->array[map->y - 1][x] == '1')
		x++;
	if (map->array[map->y - 1][x] != '\0')
		error_wall(map);
}

static void	check_pec(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->array[y][x] == 'P')
				map->p += 1;
			else if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'D')
				map->d += 1;
			else if (map->array[y][x] == '0' || map->array[y][x] == '1')
				;
			else
				error_pec(map);
		}
	}
	if (map->p != 1 || map->e != 1 || map->c < 1 || map->d < 1)
		error_pec(map);
}

void	map_check(t_map *map)
{
	check_file(map);
	map_array(map);
	check_size(map);
	check_wall(map);
	check_pec(map);
	check_path(map);
	ft_free_array(map->copy);
}

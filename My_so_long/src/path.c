/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:19:57 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/11 20:10:24 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **copy_map(char **map, int heigth)
{
	char **copy;
	int i;

	copy = malloc(sizeof(char *) * (heigth + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < heigth)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);	
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int find_player(char **map, int *px, int *py)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int check_reachable(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int check_path(t_game *game)
{
	char **map_copy;
	int px;
	int py;

	map_copy = copy_map(game->map, game->height);
	if (!map_copy)
	{
		free_map(game->map);
		return (write(2, "Error\nFailed to copy map\n", 26), 0);
	}
	if (!find_player(map_copy, &px, &py))
		return (write(2, "Error\nPlayer not found\n", 24), 0);
	flood_fill(map_copy, px, py);
	if (!check_reachable(map_copy))
	{
		free_map(map_copy);
		return (write(2, "Error\nUnreachable C or E\n", 26), 0);
	}
	free_map(map_copy);
	return (1);
}
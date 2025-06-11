/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:38:56 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/11 20:24:21 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_walls(t_game *game, int x, int y, char current)
{
	if ((y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1)
		&& current != '1')
	{
		write(2, "Error\nMap not surrounded by walls\n", 35);
		return (0);
	}
	return (1);
}

int	check_tile(t_game *game, char c)
{
	if (!ft_strchr("01CEP", c))
	{
		write(2, "Error\nInvalid character in map\n", 32);
		return (0);
	}
	if (c == 'P')
		game->player_count++;
	else if (c == 'E')
		game->exit_count++;
	else if (c == 'C')
		game->collectible_count++;
	return (1);
}

int	check_line(t_game *game, int y)
{
	int		x;
	char	current;

	x = 0;
	while (x < game->width)
	{
		current = game->map[y][x];
		if (!check_tile(game, current))
			return (0);
		if (!check_walls(game, x, y, current))
			return (0);
		x++;
	}
	return (1);
}

int	check_counts(t_game *game)
{
	if (game->player_count != 1)
		return (write(2, "Error\nWrong number of players\n", 31), 0);
	if (game->exit_count != 1)
		return (write(2, "Error\nWrong number of exits\n", 29), 0);
	if (game->collectible_count < 1)
		return (write(2, "Error\nNo collectibles on map\n", 30), 0);
	return (1);
}

int	check_map(t_game *game)
{
	int	line_len;
	int	y;

	y = 0;
	while (y < game->height)
	{
		line_len = (int)ft_strlen(game->map[y]);
		if (line_len != game->width + 1)
		{
			write(2, "Error\nMap is not rectangular\n", 30);
			return (0);
		}
		if (!check_line(game, y))
			return (0);
		y++;
	}
	if (!check_counts(game))
		return (0);
	if (!check_path(game))
		return (0);
	return (1);
}
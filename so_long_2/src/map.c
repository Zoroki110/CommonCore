/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:23:58 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 08:30:01 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define MAX_HEIGHT 1000

int	init_map(t_game *game)
{
	game->map = (char **)malloc(sizeof(char *) * MAX_HEIGHT);
	if (!game->map)
	{
		perror("malloc");
		return (0);
	}
	return (1);
}

int	read_lines(int fd, t_game *game)
{
	char	*line;
	int		index;
	int		len;

	index = 0;
	line = get_next_line(fd);
	while (line && index < MAX_HEIGHT - 1)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[index] = line;
		index++;
		line = get_next_line(fd);
	}
	game->map[index] = NULL;
	game->height = index;
	if (index > 0)
		game->width = (int)ft_strlen(game->map[0]);
	else
		game->width = 0;
	return (1);
}

int	read_map(const char *filename, t_game *game)
{
	int	fd;

	if (!init_map(game))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		free_map(game->map);
		return (0);
	}
	if (!read_lines(fd, game))
	{
		close(fd);
		free_map(game->map);
		return (0);
	}
	close(fd);
	return (1);
}

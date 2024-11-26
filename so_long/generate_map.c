/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:21 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/26 16:08:57 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_line_map(t_map *map)
{
	int	fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		error_open();
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->file = ft_strjoin(map->file, map->line); 
		free(map->line);
		if (!map->file)
			ft_exit_free(map);
		map->y++;
	}
	if (map->line == NULL)
		exit(EXIT_FAILURE);
	close(fd);
}
void	map_array(t_map *map)
{
	ft_line_map(map);
	map->array = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->array || !map->copy)
		ft_exit_free(map);
	free(map->file);
}
/*int	fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		error_open();
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->file = ft_strjoin(map->file, map->line); 
		free(map->line);
		if (!map->file)
			ft_exit_free(map);
		map->y++;
	}*/
	/*if (map->line == NULL)
		exit(EXIT_FAILURE);
	close(fd);*/
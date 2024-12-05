/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:21 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/05 18:21:04 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_line_map(t_map *map)
{
	int		fd;
	char	*tmp;

	map->y = 0;
	map->line = NULL;
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		error_open();
	while (1)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		tmp = ft_strjoin(map->file, map->line);
		if (!tmp)
			return ;
		free(map->file);
		map->file = tmp;
		free(map->line);
		if (!map->file)
			ft_exit_free(map);
		map->y++;
	}
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

size_t	ft_strlen2(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (0);
	str = (char *)s;
	while (str[i])
		i++;
	return (i);
}

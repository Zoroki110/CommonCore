/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:14 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/26 15:17:33 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_array(char **str, int i)
{
	if (str == NULL)
		return 0;
	while (i > 0)
	{
		if (str != NULL)
			free(str[i--]);
	}
	free(str);
	return (0);
}

void	ft_exit_free(t_map *map)
{
	if (map->array)
		free(map->array);
	if (map->copy)
		free(map->copy);
	if (map->line)
		free(map->line);
	if (map->file)
		free(map->file);
	exit(EXIT_FAILURE);
}
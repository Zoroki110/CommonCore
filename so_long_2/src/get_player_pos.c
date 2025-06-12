/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:01:57 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 08:42:55 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_exit_pos(t_game *g, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->height && g->map[i])
	{
		j = 0;
		while (j < g->width && g->map[i][j])
		{
			if (g->map[i][j] == 'E')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_player_pos(t_game *g, int *x, int *y)
{
	int			i;
	int			j;
	static int	last_x;
	static int	last_y;

	i = 0;
	while (i < g->height && g->map[i])
	{
		j = 0;
		while (j < g->width && g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	if (last_x == 0 && last_y == 0)
		find_exit_pos(g, &last_x, &last_y);
	*x = last_x;
	*y = last_y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:32:03 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 08:35:09 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect_item(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'C')
		g->collectible_count--;
}

int	check_exit(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'E' && g->collectible_count == 0)
	{
		ft_putstr_fd("Congratulations! You won!\n", 1);
		exit_game(g, "Game completed successfully.\n");
		return (1);
	}
	return (0);
}

void	clear_old_position(t_game *g, int old_x, int old_y)
{
	if (g->map[old_y][old_x] != 'E')
		g->map[old_y][old_x] = '0';
}

void	set_new_position(t_game *g, int x, int y)
{
	char	original;

	original = g->map[y][x];
	if (original != 'E')
		g->map[y][x] = 'P';
}

int	move_player(t_game *g, int d_x, int d_y)
{
	int	x;
	int	y;
	int	nx;
	int	ny;

	get_player_pos(g, &x, &y);
	nx = x + d_x;
	ny = y + d_y;
	if (nx < 0 || nx >= g->width || ny < 0 || ny >= g->height)
		return (0);
	if (g->map[ny][nx] == '1')
		return (0);
	collect_item(g, nx, ny);
	clear_old_position(g, x, y);
	set_new_position(g, nx, ny);
	check_exit(g, nx, ny);
	render_map(g);
	return (1);
}

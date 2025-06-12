/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:03:52 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 08:34:09 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_background(t_game *g, int x, int y)
{
	render_tile(g, g->img_floor, x, y);
	if (g->map[y][x] == '1')
		render_tile(g, g->img_wall, x, y);
	else if (g->map[y][x] == 'E')
		render_tile(g, g->img_exit, x, y);
	else if (g->map[y][x] == 'C')
		render_tile(g, g->img_collect, x, y);
}

int	is_player_here(t_game *g, int x, int y)
{
	int	px;
	int	py;

	get_player_pos(g, &px, &py);
	return (px == x && py == y);
}

void	render_player_if_present(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'P' || is_player_here(g, x, y))
		render_tile(g, g->img_player, x, y);
}

void	render_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			render_background(g, x, y);
			render_player_if_present(g, x, y);
			x++;
		}
		y++;
	}
}

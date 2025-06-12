/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:38:31 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 08:31:48 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_images(t_game *g)
{
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_collect)
		mlx_destroy_image(g->mlx, g->img_collect);
}

void	cleanup_mlx(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}

int	close_window(t_game *g)
{
	destroy_images(g);
	cleanup_mlx(g);
	if (g->map)
		free_map(g->map);
	exit(0);
	return (0);
}

void	exit_game(t_game *g, char *message)
{
	if (message)
		ft_putstr_fd(message, 1);
	destroy_images(g);
	cleanup_mlx(g);
	if (g->map)
		free_map(g->map);
	exit(0);
}

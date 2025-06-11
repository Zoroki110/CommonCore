/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:32:38 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/11 20:20:25 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_direction(int keycode, int *dx, int *dy)
{
	if (keycode == 'w' || keycode == 65362)
	{
		*dx = 0;
		*dy = -1;
		return (1);
	}
	else if (keycode == 's' || keycode == 65364)
	{
		*dx = 0;
		*dy = 1;
		return (1);
	}
	else if (keycode == 'a' || keycode == 65361)
	{
		*dx = -1;
		*dy = 0;
		return (1);
	}
	else if (keycode == 'd' || keycode == 65363)
	{
		*dx = 1;
		*dy = 0;
		return (1);
	}
	return (0);
}

void	print_moves(t_game *g)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(g->moves, 1);
	ft_putchar_fd('\n', 1);
}

int	handle_move(t_game *g, int keycode)
{
	int	dx;
	int	dy;

	if (get_direction(keycode, &dx, &dy))
	{
		if (move_player(g, dx, dy))
		{
			g->moves++;
			print_moves(g);
		}
		return (1);
	}
	return (0);
}

int	handle_escape(t_game *g)
{
	exit_game(g, "Game closed by user.\n");
	return (1);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == 65307)
		return (handle_escape(g));
	else
		return (handle_move(g, keycode));
}

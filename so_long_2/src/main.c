/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:17:28 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/11 20:33:00 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int check_arguments(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Error\nUsage: ./so_long map.ber\n", 32);
        return (0);
    }
    if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
    {
        write(2, "Error\nMap must have .ber extension\n", 36);
        return (0);
    }
    return (1);
}

void init_game_struct(t_game *game)
{
    game->map = NULL;
    game->mlx = NULL;
    game->win = NULL;
    game->img_wall = NULL;
    game->img_floor = NULL;
    game->img_player = NULL;
    game->img_exit = NULL;
    game->img_collect = NULL;
    game->player_count = 0;
    game->exit_count = 0;
    game->collectible_count = 0;
    game->moves = 0;
    game->width = 0;
    game->height = 0;
}

int setup_game(char *filename, t_game *game)
{
    if (!read_map(filename, game))
        return (0);
    if (!check_map(game))
    {
        if (game->map)
            free_map(game->map);
        return (0);
    }
    if (!init_window(game))
    {
        if (game->map)
            free_map(game->map);
        return (0);
    }
    if (!load_textures(game))
    {
        cleanup_mlx(game);
        if (game->map)
            free_map(game->map);
        return (0);
    }
    return (1);
}

void start_game_loop(t_game *game)
{
    render_map(game);
    mlx_key_hook(game->win, key_hook, game);
    mlx_hook(game->win, 17, 0, close_window, game);
    mlx_loop(game->mlx);
}

int main(int argc, char **argv)
{
    t_game game;
    
    if (!check_arguments(argc, argv))
        return (1);
    init_game_struct(&game);
    if (!setup_game(argv[1], &game))
        return (1);
    start_game_loop(&game);
    return (0);
}
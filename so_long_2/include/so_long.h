#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../Libft/include/ft_printf.h"
# include "../Libft/include/libft.h"
# include "../Libft/include/get_next_line.h"

# define TILE_SIZE 64

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	char	**map;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		moves;
}	t_game;

//main.c
int	check_arguments(int argc, char **argv);
void	init_game_struct(t_game *game);
int	setup_game(char *filename, t_game *game);
void	start_game_loop(t_game *game);

//map.c
int	init_map(t_game *game);
int	read_lines(int fd, t_game *game);
int	read_map(const char *filename, t_game *game);

//path.c
char **copy_map(char **map, int heigth);
int find_player(char **map, int *px, int *py);
void flood_fill(char **map, int x, int y);
int check_reachable(char **map);
int check_path(t_game *game);

//check.c
int	check_walls(t_game *game, int x, int y, char current);
int	check_tile(t_game *game, char c);
int	check_line(t_game *game, int y);
int	check_counts(t_game *game);
int check_map(t_game *game);

//free.c
void	free_map(char **map);
void	destroy_images(t_game *g);
void	cleanup_mlx(t_game *g);
int	close_window(t_game *g);
void	exit_game(t_game *g, char *message);

//generate_map.c
int init_window(t_game *game);

//file_img.c
int load_textures(t_game *g);

//map_print.c
void render_tile(t_game *g, void *img, int x, int y);
void render_background(t_game *g, int x, int y);
int is_player_here(t_game *g, int x, int y);
void render_player_if_present(t_game *g, int x, int y);
void render_map(t_game *g);

//get_player_pos.c
void	get_player_pos(t_game *g, int *x, int *y);

//move_player.c
void	collect_item(t_game *g, int x, int y);
int	check_exit(t_game *g, int x, int y);
void	clear_old_position(t_game *g, int x, int y);
void	set_new_position(t_game *g, int x, int y);
int	move_player(t_game *g, int d_x, int d_y);

//key_move.c
int	get_direction(int keycode, int *dx, int *dy);
void	print_moves(t_game *g);
int	handle_move(t_game *g, int keycode);
int	handle_escape(t_game *g);
int	key_hook(int keycode, t_game *g);

#endif
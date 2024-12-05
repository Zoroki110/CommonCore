/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:16:56 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/04 13:36:58 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
/*# include <X11/X.h>*/
# include "../Libft/include/ft_printf.h"
# include "../Libft/include/get_next_line.h"
# include "../Libft/include/libft.h"
/*# include <X11/keysym.h>*/

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define S 1
# define D 2
# define A 0
# define ESC 53
# define IMG_PXL 64
# define WND_NAME "so_long"

typedef struct s_player
{
	int			y;
	int			x;
}				t_player;

typedef struct s_exit
{
	int			y;
	int			x;
}				t_exit;

typedef struct s_image
{
	void		*empty;
	void		*collectible;
	void		*wall;
	void		*exit;
	void		*enemy;
	void		*player_right1;
	void		*player_left1;
	void		*player_up1;
	void		*player_down1;
}				t_image;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			c;
	int			p;
	int			e;
	int			check_c;
	int			check_e;
	int			exit;
	int			move;
	void		*mlx;
	void		*wnd;
	t_image		img;
	t_player	player;
	t_exit		t;
}				t_map;

int				found_exit(t_map *map);
void			ee(t_map *map, int x, int y);
void			eee(t_map *map, int x, int y);
void			eeee(t_map *map, int x, int y);

void			error_filename(void);
void			error_open(void);
void			error_size(t_map *map);
void			error_wall(t_map *map);
void			error_pec(t_map *map);

void			map_array(t_map *map);
void			ft_line_map(t_map *map);
size_t			ft_strlen2(const char *s);

void			map_check(t_map *map);
void			map_init(t_map *map, char **av);

int				ft_free_array(char **str);
void			ft_exit_free(t_map *map);

int				found_player(t_map *map);
int				key_move(int key, t_map *map);

int				move_on_path(int x, int y, t_map *map);
void			check_path(t_map *map);

void			file_image_player(t_map *map);
void			file_to_image(t_map *map);

void			map_printer(t_map *map);
int				ft_close(t_map *map);
void			ft_victory(t_map *map);

void			update_map(t_map *map, int x, int y);
void			move_player_right(t_map *map, int x, int y);
void			move_player_left(t_map *map, int x, int y);
void			move_player_down(t_map *map, int x, int y);
void			move_player_up(t_map *map, int x, int y);

int				go_left(t_map *map);
int				go_right(t_map *map);
int				go_up(t_map *map);
int				go_down(t_map *map);

void			move_check1(t_map *map, int x, int y, int key);
void			move_check2(t_map *map, int x, int y, int key2);

void			print_move(t_map *map);

#endif

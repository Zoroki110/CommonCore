/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:16:56 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/25 18:18:59 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
/*# include <X11/X.h>*/
# include "Libft/include/ft_printf.h"
# include "Libft/include/get_next_line.h"
# include "Libft/include/libft.h"
/*# include <X11/keysym.h>*/

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define IMG_PXL 64
# define WND_NAME "so_long"

typedef struct s_player
{
	int			y;
	int			x;
}				t_player;

typedef struct s_image
{
	void		*empty;
	void		*collectible;
	void		*wall;
	void		*exit;
	void		*enemy1;
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
}				t_map;

void			error_filename(void);
void			error_open(void);
void			error_size(t_map *map);
void			error_wall(t_map *map);
void			error_PEC(t_map *map);

void			map_array(t_map *map);

void			map_check(t_map *map);

int				ft_free_array(char **str, int i);
void			ft_exit_free(t_map *map);

void			found_player(t_map *map);

void			move_on_path(int x, int y, t_map *map);
void			check_path(t_map *map);

#endif

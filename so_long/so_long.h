/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:16:56 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/11 18:27:13 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
//# include <mlx.h>
//# include <X11/X.h>
//# include <X11/keysym.h>
# include "Libft/include/libft.h"
# include "Libft/include/ft_printf.h"
# include "Libft/include/get_next_line.h"


//define touche q/z/s/d + haut,bas,gauche,droite 
//Structure pour : Player//Maps//image
//Player : x, y
//Image : empty, collectible, wall, exit, layer_left1
//          player_right1, player_up2, player_down1, playerleft2,
//          player_right2, player_up2, player_down2, enemy
//Maps : fd, line, file, array, copy, filename, y, x, e, c, c_check, e_check
//         p, exit, moves, mlx, wnd, t_img img, t_player player

/*
Structure code fonction : 
Map checker(t_map *map) : 
*/
typedef struct s_player
{
    int	y;
    int x;
}	t_player;

typedef struct s_image
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*enemy1;
	void	*player_right1;
	void	*player_left1;
	void	*player_up1;
	void	*player_down1;
}		t_image;

typedef struct s_map
{
	int fd;
	char		*line;
	char		*file;
	char		**array;
	char 		**copy;
	char		*filename;
	int 		y;
	int 		x;
	int 		c;
	int 		p;
	int 		e;
	int 		check_c;
	int 		check_e;
	int 		exit;
	int 		move;
	void 		*mlx;
	void		*wnd;
	t_image		img;
	t_player	player;
}			t_map; 

void	error_filename(void);
void	error_open(void);
void	error_size(t_map *map);
void	error_wall(t_map *map);
void 	error_PEC(t_map *map);

void 	map_array(t_map *map);

void	map_check(t_map *map);

int		ft_free_array(char **str, int i);
void	ft_exit_free(t_map *map);

#endif

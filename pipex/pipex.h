/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:04:02 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/18 15:28:27 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "../include/ft_printf.h"
# include "../include/get_next_line.h"
# include "../include/libft.h"

typedef struct s_args
{
    char    **cmd1;
    char    **cmd2;
    char    *cmd1_path;
    char    *cmd2_path;
    int pipe_fd[2];
}   t_args;

typedef struct s_path
{
    char    **paths;
    char    *path_var;
    char    *path_full;
    char    *tmp;
}
int     error_file(char *filename);
void	ft_free_array(char **array);

#endif 
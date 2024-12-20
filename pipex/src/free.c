/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:48:17 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/20 10:13:57 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int file_error(char *filename)
{
    write(2, filename, ft_strlen(filename));
    perror(" ");
    exit(EXIT_FAILURE);
}

void	ft_free_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	*ft_return(char **array, void *value)
{
	ft_free_array(array);
	return (value);
}

void ft_args_free(char *arg1, char *arg2, t_args *arg3)
{
	free(arg1);
	free(arg2);
	free(arg3);
}

void	big_free(char **cmd1, char **cmd2, char *path1, char *path2)
{
	ft_free_array(cmd1);
	ft_free_array(cmd2);
	free(path1);
	free(path2);
}

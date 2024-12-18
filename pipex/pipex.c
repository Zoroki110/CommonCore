/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:33:11 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/18 14:38:01 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_input(int ac, char **av)
{
    if (ac != 5)
    {
        ft_putendl_fd("Error, './pipex file1 cmd1 cmd2 file2'", 2);
        exit(EXIT_FAILURE);
    }
    if (open(av[1], O_RDONLY) < 0)
    {
        open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        error_file(av[1]);
    }
    if (open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777) < 0)
        error_file(av[4]);
}

t_args	args_init(char **av, char **env)
{
	t_args	*args;
	
	args = malloc(sizeof(t_args));
	if (!args)
	    return (NULL);
	args->cmd1 = ft_split(av[2], " ");
	args->cmd2 = ft_split(av[3], " ");
    if (!args->cmd1[0] || !args->cmd2[0])
    {
        ft_free_array(args->cmd1);
        ft_free_array(args->cmd2);
        ft_putendl_fd("Error, command not found", 2);
        exit(EXIT_FAILURE);
    }
    args->cmd1_path = find_path
    args->cmd2_path = 
    
}

int main(int ac, char **av, char **env)
{
	t_args	args;
	pid_t	child_1;
	pid_t	child_2;

    //First check if input is correct 
    check_input(ac, av);
	args = args_init(av, env);
}
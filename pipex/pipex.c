/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:33:11 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/20 09:08:57 by trouilla         ###   ########.fr       */
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
        file_error(av[1]);
    }
    if (open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777) < 0)
        file_error(av[4]);
}

t_args	*args_init(char **av, char **env)
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
    args->cmd1_path = find_path(args->cmd1[0], env);
    args->cmd2_path = find_path(args->cmd2[0], env);
    if (!args->cmd1[0] || !args->cmd2[0])
    {
        ft_args_free(args->cmd1_path, args->cmd2_path, args);
        ft_putendl_fd("ERROR, command was not found", 2);
        exit(EXIT_FAILURE);
    }
    return (args);
}

int main(int ac, char **av, char **env)
{
	t_args	*args;
	pid_t	child1;
	pid_t	child2;

    check_input(ac, av);
	args = args_init(av, env);
    if (pipe(args->pipe_fd) < 0)
    {
        return (perror("Error PIPE"), big_free(args->cmd1, args->cmd2, 
                args->cmd1_path, args->cmd2_path), free(args), exit(1), 0);
    }
    child1 = fork;
    if (child1 == 0)
        manage_child1(args, av[1], env);
    child2 = fork;
    if (child2 == 0)
        manage_child2(args, av[4], env);
    close(args->pipefd[0]);
    close(args->pipefd[1]);
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
    big_free(args->cmd1, args->cmd2, args->cmd1_path, args->cmd2_path);
    free(args);
    exit(0);
}

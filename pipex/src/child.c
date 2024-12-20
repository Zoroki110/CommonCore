/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:24:50 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/20 10:17:33 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	manage_child1(t_args *args, char *in, char **env)
{
	int	infile;

	infile = open(in, O_RDONLY);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(args->pipe_fd[1], STDOUT_FILENO);
	close(args->pipe_fd[0]);
	execve(args->cmd1_path, args->cmd1, env);
	exit(EXIT_SUCCESS);
}

void	manage_child2(t_args *args, char *out, char **env)
{
	int outfile;

	outfile = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(args->pipe_fd[0], STDIN_FILENO);
	close(args->pipe_fd[1]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execve(args->cmd2_path, args->cmd2, env);
	exit(EXIT_SUCCESS);
}

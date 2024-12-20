/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:24:50 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/20 08:58:11 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	manage_child1(t_args *args, char *in, char **env)
{
	int	infile;

	infile = open(in, O_RDONLY);
	dup2(infile, STDIN_FILEO);
	close(infile);
	dup2(args->pipefd[1], STDOUT_FILEO);
	close(args->pipefd[0]);
	execve(args->cmd_path1, args->cmd1, env);
	exit(EXIT_SUCCESS);
}

void	manage_child2(t_args *args, char *out, char **env)
{
	int outfile;

	outfile = open(out, O_WONLY | O_CREAT | O_TRUNC, 0777);
	dup2(args->pipefd[0], STDIN_FILEO);
	close(args->pipefd[1]);
	dup2(outfile, STDOUT_FILEO);
	close(outfile);
	execve(args->cmd2_path, args->cmd2, env);
	exit(EXIT_SUCCESS);
}

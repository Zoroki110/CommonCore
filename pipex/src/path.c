/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 07:46:52 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/20 10:51:04 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_path(char	*cmd, char **env)
{
	int	i;
	t_path	path_struct;

	path_struct.path_var = get_path(env);
	if (!path_struct.path_var)
		return (NULL);
	path_struct.paths = ft_split(path_struct.path_var, ':');
	if (!path_struct.paths)
		return (NULL);
	i = -1;
	while (path_struct.paths[i++])
	{
		path_struct.tmp = ft_strjoin(path_struct.paths[i], "/");
		if (!path_struct.tmp)
			return ((char *)ft_return(path_struct.paths, NULL));
		path_struct.path_full = ft_strjoin(path_struct.tmp, cmd);
		free(path_struct.tmp);
		if (!path_struct.path_full)
			return ((char *)ft_return(path_struct.paths, NULL));
		if (access(path_struct.path_full, F_OK | X_OK) == 0)
			return ((char *)ft_return(path_struct.paths, 
										path_struct.path_full));
		free(path_struct.path_full);
	}
	return (ft_return(path_struct.paths, NULL));
}

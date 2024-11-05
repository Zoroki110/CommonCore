/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:10:57 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/05 21:47:28 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_stash(int fd, char *stash)
{
	char	*buff[BUFFER_SIZE + 1];
	int		readed;
	char	*tmp;

	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(stash);
			return (NULL);
		}
		buff[readed] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
		if (stash && ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

static int	get_len_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 2);
	return (i + 1);
}

static char	*add_to_line(char *s)
{
	char	*line;
	int		i;
	int		len_line;

	i = 0;
	len_line = get_len_line(s);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	stash = ft_read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = add_to_line(stash);
}

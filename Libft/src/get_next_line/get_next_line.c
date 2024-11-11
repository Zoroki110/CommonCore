/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:10:57 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/06 18:45:13 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_stash(int fd, char *stash)
{
	char	buff[BUFFER_SIZE + 1];
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

	if (!s || !*s)
		return (NULL);
	len_line = get_len_line(s);
	line = malloc(sizeof(char) * (len_line));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

static char	*add_static(char *s)
{
	char	*stash;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	stash = ft_strdup(s + i + 1);
	free(s);
	return (stash);
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
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = add_to_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = add_static(stash);
	return (line);
}
/*
int main()
{
	int	fd;

	fd = open("txt.txt", O_RDONLY);
	char *str;
	for (int i = 0; i < 55555; i++)
	{			
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	//system("leaks a.out");
	return 0;
}
*/

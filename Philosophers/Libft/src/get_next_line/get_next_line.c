/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:42:37 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/25 12:44:51 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_leftover(char *stash)
{
	char	*leftover;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	leftover = malloc(ft_strlen_gnl(stash) - i + 1);
	if (!leftover)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i])
		leftover[j++] = stash[i++];
	leftover[j] = '\0';
	free(stash);
	return (leftover);
}

static char	*handle_final_line(char **stash)
{
	char	*line;

	if (!*stash || !**stash)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	line = extract_line(*stash);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	free(*stash);
	*stash = NULL;
	return (line);
}

static char	*read_and_update_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = *stash;
		*stash = ft_strjoin_gnl(*stash, buffer);
		free(temp);
		if (!*stash)
			return (NULL);
		if (ft_strchr_gnl(*stash, '\n'))
			break ;
	}
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	stash = read_and_update_stash(fd, &stash);
	if (!stash)
		return (NULL);
	if (ft_strchr_gnl(stash, '\n'))
	{
		line = extract_line(stash);
		if (!line)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash = save_leftover(stash);
		return (line);
	}
	return (handle_final_line(&stash));
}

/*
# include <stdio.h>

int	main(void)
{
	int	fd = open("t.txt", O_RDONLY);
	char	*line;

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	//system("leaks a.out");
	return (0);
} */

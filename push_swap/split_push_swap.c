/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:26:22 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/10 22:14:41 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	count_words(char *str, char charset)
{
	int		count;
	bool	in_the_word;

	count = 0;
	while (*str)
	{
		in_the_word = false;
		while (*str == charset)
			++str;
		while (*str != charset && *str)
		{
			if (!in_the_word)
			{
				++count;
				in_the_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char charset)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == charset)
		++cursor;
	while ((str[cursor + len] != charset) && str[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[cursor] != charset) && str[cursor])
		next_word[i++] = str[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *str, char charset)
{
	int		word_count;
	char	**result;
	int		i;

	i = 0;
	word_count = count_words(str, charset);
	if (!word_count)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!result)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(str, charset);
	}
	result[i] = NULL;
	return (result);
}

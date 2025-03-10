/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:30:54 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/16 15:08:25 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

static int	ft_calc_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*res;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = ft_calc_start(s1, set);
	end = ft_calc_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * ((end - start) + 2));
	if (!res)
		return (NULL);
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
/*
int main(void)
{
	char str1[] = "";
	char set1[] = "";
	char *result1 = ft_strtrim(str1, set1);

	char str2[] = "abcxxxyabc";
	char set2[] = "abc";
	char *result2 = ft_strtrim(str2, set2);

	char str3[] = "42";
	char set3[] = "0123456789";
	char *result3 = ft_strtrim(str3, set3);

	printf("Original: '%s' -- Trimmed: '%s'\n", str1, result1);
	printf("Original: '%s' -- Trimmed: '%s'\n", str2, result2);
	printf("Original: '%s' -- Trimmed: '%s'\n", str3, result3);

	free(result1);
	free(result2);
	free(result3);

	return 0;
}
*/
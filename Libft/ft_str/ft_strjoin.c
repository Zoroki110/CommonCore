/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:23:29 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/10 19:38:42 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s);
}
/*
int	main(void)
{
	char *tab = "Hello";
	char *sep = "--";

	char *result = ft_strjoin(tab, sep);
	printf("%s\n", result);
	free(result);

	return 0;
}
*/

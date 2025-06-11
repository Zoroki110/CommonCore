/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:19:10 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/10 19:36:01 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
/*
int	main(void)
{
	char str[] = "Mais non! Quoi. Comment ose tu!";
	char ch = '.';
	char *ret;

	ret = ft_strchr(str, ch);
	printf("String after is - |%s|\n", ch, ret);
	return (0);
}*/

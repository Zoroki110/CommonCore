/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:18:23 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/18 17:39:18 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
/*
int main ()
{
	char str[] = "Alors . on chercher la .derniere occurence. monstre";
	char ch = '.';
	char *res;

	res = ft_strrchr(str, ch);
	printf("%s\n", res);
	return (0);
}*/
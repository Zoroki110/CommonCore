/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:18:57 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/17 02:27:13 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (dst[i])
		i++;
	res = 0;
	while (src[res])
		res++;
	if (dstsize <= i)
		res += dstsize;
	else
		res += i;
	j = 0;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char dest[20] = "Yoooo, ";
	const char *src = "ma biche!";
	size_t size = sizeof(dest);

	size_t result = ft_strlcat(dest, src, size);

	printf("Destination après ft_strlcat : %s\n", dest);
	printf("Longueur totale : %zu\n", result);

	return (0);
}*/

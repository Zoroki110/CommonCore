/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:18:52 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/17 00:14:22 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int	main(void)
{
	char dest[5] = "Yooo";
	const char *src = "ma biche!";
	size_t size = sizeof(dest);

	size_t result = ft_strlcpy(dest, src, size);

	printf("Destination après ft_strlcpy : %s\n", dest);
	printf("Longueur totale : %zu\n", result);
	
	size_t result2 = strlcpy(dest, src, size);
	printf("Destination après strlcpy : %s\n", dest);
	printf("Longueur totale : %zu\n", result2);

	return (0);
}
*/
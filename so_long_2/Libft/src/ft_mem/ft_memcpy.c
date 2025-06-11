/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:19:34 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/10 18:11:53 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}
/*
int	main(void)
{
	char src[50] = "Yo joe comme on ce retrouve !";
	char dest[50];
	char *ret;

	ret = ft_memcpy(dest, src, 10);
	printf("%s", ret);
	return (0);
}*/

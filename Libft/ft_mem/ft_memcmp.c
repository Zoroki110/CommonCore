/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:19:46 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/10 18:11:52 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*chs1;
	unsigned char	*chs2;

	i = 0;
	chs1 = (unsigned char *)s1;
	chs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (chs1[i] != chs2[i])
			return (chs1[i] - chs2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str1[50] = "Yo batard de fion";
	char str2[50] = "Yo batarr de con";
	int n = 17;
	printf("%d", ft_memcmp(str1, str2, n));
	return (0);
}*/

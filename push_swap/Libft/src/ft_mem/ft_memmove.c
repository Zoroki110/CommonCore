/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:19:25 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/10 22:13:54 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
/*
int	main(void)
{
	char str1[50];
	char str2[50] = "Recopier oh oui";
	char *ret;

	ret = ft_memmove(str1, str2, 21);
	printf("%s", ret);
	return (0);
}*/

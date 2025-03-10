/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:52:03 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:52:06 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chs1;
	unsigned char	*chs2;
	size_t			i;

	chs1 = (unsigned char *)s1;
	chs2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (chs1[i] != chs2[i])
			return (chs1[i] - chs2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:55:37 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:55:38 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;

	if (!dest && !src)
		return (0);
	destlen = 0;
	while (dest[destlen])
		destlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size < destlen)
		return (srclen + size);
	i = 0;
	while (src[i] && i < (size - destlen - 1) && (size - destlen) >= 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (srclen + destlen);
}

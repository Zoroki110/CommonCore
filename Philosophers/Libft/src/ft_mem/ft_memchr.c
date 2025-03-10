/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:51:38 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:51:45 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*chs;

	chs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*chs == (unsigned char)c)
			return (chs);
		i++;
		chs++;
	}
	return (NULL);
}
/*
int main(void)
{
    char data[] = { 'a', 'b', 'c', 'd', '\0', 'e', 'f' };
    char *result = ft_memchr(data, 'e', 7);

    if (result != NULL)
        printf("Found 'e' at position: 0%ld\n", result - data);
    else
        printf("Character not found.\n");

    return 0;
}
*/

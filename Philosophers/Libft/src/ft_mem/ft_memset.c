/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:52:49 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:52:50 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
/*
int	main(void)
{
	char str1[50] = "Hello, World!";
	char str2[50] = "Libft testing";

	printf("Before memset: %s\n", str1);
	ft_memset(str1, '*', 5);

	// Should modify first 5 characters to '*'
	printf("After memset: %s\n", str1);

	printf("Before memset: %s\n", str2);
	ft_memset(str2, '-', 7);
	
	// Should modify first 7 characters to '-'
	printf("After memset: %s\n", str2);  

	return (0);
}
*/
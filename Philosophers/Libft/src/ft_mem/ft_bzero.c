/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:49:28 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 17:05:59 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}
/*
int	main(void)
{
	char str1[50] = "Hello, World!";
	char str2[50] = "Libft testing";

	printf("Before bzero: %s\n", str1);
	ft_bzero(str1, 6);
	printf("After bzero: ");
	for (int i = 0; i < 13; i++)
		printf("%d ", str1[i]); // Print the byte values to verify zeroing
	return (0);
}
*/

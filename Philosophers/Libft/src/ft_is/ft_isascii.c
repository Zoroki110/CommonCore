/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:50:27 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:50:34 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int test1 = 65;  // 'A'
	int test2 = 127; // DEL (ASCII limit)
	int test3 = 0;   // NULL character
	int test4 = 200; // Non-ASCII character
	int test5 = -5;  // Negative value

	printf("Test with %d: %d\n", test1, ft_isascii(test1)); // Should return 1
	printf("Test with %d: %d\n", test2, ft_isascii(test2)); // Should return 1
	printf("Test with %d: %d\n", test3, ft_isascii(test3)); // Should return 1
	printf("Test with %d: %d\n", test4, ft_isascii(test4)); // Should return 0
	printf("Test with %d: %d\n", test5, ft_isascii(test5)); // Should return 0

	return (0);
}
*/
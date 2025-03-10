/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:51:12 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:51:14 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	int test1 = 32;  // Space character (printable)
	int test2 = 65;  // 'A' (printable)
	int test3 = 127; // Non-printable (DEL)

	printf("Test with %d: %d\n", test1, ft_isprint(test1)); // Should return 1
	printf("Test with %d: %d\n", test2, ft_isprint(test2)); // Should return 1
	printf("Test with %d: %d\n", test3, ft_isprint(test5)); // Should return 0

	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:50:46 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:50:48 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	char test1 = '5';
	char test2 = 'a';
	char test3 = '#';

	printf("Test with '%c': %d\n", test1, ft_isdigit(test2)); // Should return 1
	printf("Test with '%c': %d\n", test2, ft_isdigit(test4)); // Should return 0
	printf("Test with '%c': %d\n", test3, ft_isdigit(test5)); // Should return 0

	return (0);
}
*/
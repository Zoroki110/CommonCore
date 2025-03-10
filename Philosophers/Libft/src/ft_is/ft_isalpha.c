/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:50:16 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:50:17 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char test1 = 'A';
	char test2 = '@';

	printf("Test with '%c': %d\n", test1, ft_isalpha(test1)); // Should return 1
	printf("Test with '%c': %d\n", test4, ft_isalpha(test2)); // Should return 0

	return (0);
}
*/

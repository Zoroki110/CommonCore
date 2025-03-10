/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:50:00 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:50:02 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char test1 = 'A';
	char test2 = '#';

	printf("Test with '%c': %d\n", test1, ft_isalnum(test1)); // Should return 1
	printf("Test with '%c': %d\n", test4, ft_isalnum(test2)); // Should return 0

	return (0);
}
*/

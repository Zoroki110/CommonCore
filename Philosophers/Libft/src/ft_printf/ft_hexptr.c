/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:17:28 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/15 17:37:42 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexptr(unsigned long long n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
		len += ft_hexptr(n / 16);
	n = n % 16;
	if (n < 10)
		c = n + '0';
	else
		c = n + 'a' - 10;
	write(1, &c, 1);
	len++;
	return (len);
}

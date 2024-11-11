/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:28:51 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/28 17:13:14 by trouilla         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_Maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:02:19 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/08 21:35:49 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_maj(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
		len += ft_print_hex_maj(n / 16);
	n = n % 16;
	if (n < 10)
		c = n + '0';
	else
		c = n + 'A' - 10;
	write(1, &c, 1);
	len++;
	return (len);
}
/*
int main()
{
	int i = -2147483648;
	ft_print_hex_maj(i);
	return 0;
}
*/

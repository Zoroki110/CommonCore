/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:28:03 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/25 22:14:12 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_min(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
		len += ft_print_hex_min(n / 16);
	n = n % 16;
	if (n < 10)
		c = n + '0';
	else
		c = n + 'a' - 10;
	write(1, &c, 1);
	len++;
	return (len);
}
/*
int main()
{
	int i = 10;
	ft_print_hex_min(i);
	return 0;
}
*/

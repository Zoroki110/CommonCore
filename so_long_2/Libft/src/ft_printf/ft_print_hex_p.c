/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:00:49 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/28 17:13:12 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_p(void *ptr)
{
	unsigned long long		adress;
	int						count;

	count = 0;
	adress = (unsigned long long)ptr;
	write(1, "0x", 2);
	count += 2;
	if (adress == 0)
		count += write(1, "0", 1);
	else
		count += ft_hexptr(adress);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:23:28 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/26 11:35:18 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_minmax(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return (11);
}

static int	ft_neg(int nb)
{
	int	count;

	count = 0;
	write(1, "-", 1);
	count++;
	nb = nb * (-1);
	count += ft_putnbr_printf(nb);
	return (count);
}

int	ft_putnbr_printf(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (ft_minmax(nb));
	if (nb < 0)
		return (ft_neg(nb));
	if (nb > 9)
	{
		count += ft_putnbr_printf(nb / 10);
		count += ft_putnbr_printf(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		count++;
	}
	return (count);
}

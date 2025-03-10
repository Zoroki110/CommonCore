/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:22:32 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/24 14:13:16 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	nb_char;
	int		len;

	len = 0;
	nb_char = n + 48;
	if (n > 9)
	{
		len += ft_putunsigned((n / 10));
		len += ft_putunsigned((n % 10));
	}
	else
	{
		write (1, &nb_char, 1);
		len++;
	}
	return (len);
}

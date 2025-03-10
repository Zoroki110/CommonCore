/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:06:58 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/30 13:41:15 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(int c)
{
	if (c >= 0)
		return (ft_putnbr_fd_pf(c, 1));
	else
		return (ft_putunsigned((unsigned int) c));
}

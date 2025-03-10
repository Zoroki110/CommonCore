/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:22:14 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/30 13:40:45 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static int	ft_min_int(int fd)
{
	write(fd, "-2147483648", 11);
	return (11);
}

static int	ft_negative(int n, int fd)
{
	int	len;

	len = 0;
	write(fd, "-", 1);
	len++;
	len += ft_putnbr_fd_pf(-n, fd);
	return (len);
}

int	ft_putnbr_fd_pf(int n, int fd)
{
	int		len;
	char	nb_char;

	len = 0;
	nb_char = n + '0';
	if (n == -2147483648)
		return (ft_min_int(fd));
	if (n < 0)
		return (ft_negative(n, fd));
	if (n > 9)
	{
		len += ft_putnbr_fd_pf(n / 10, fd);
		len += ft_putnbr_fd_pf(n % 10, fd);
	}
	else
	{
		write(fd, &nb_char, 1);
		len++;
	}
	return (len);
}

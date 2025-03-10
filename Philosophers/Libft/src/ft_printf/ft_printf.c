/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:22:07 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/30 13:35:30 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_format(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += ft_putnbr_fd_pf(va_arg(args, int), 1);
	else if (format == 'c')
		count += ft_putchar_pf(va_arg(args, int));
	else if (format == 'x')
		count += ft_print_hex(va_arg(args, int));
	else if (format == 'X')
		count += ft_printcaps_hex(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr_fd_pf(va_arg(args, char *), 1);
	else if (format == 'u')
		count += ft_unsigned(va_arg(args, int));
	else if (format == 'p')
		count += ft_pointer(va_arg(args, void *));
	else if (format == '%')
		return (write (1, "%%", 1));
	else
		return (0);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		j;

	count = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			while (format[j + 1] == ' ')
				j++;
			count += ft_find_format(format[j + 1], args);
			j += 2;
		}
		else
		{
			write(1, &format[j], 1);
			count++;
			j++;
		}
	}
	va_end(args);
	return (count);
}

/* #include <stdio.h>
int main(void)
{
	ft_printf("%p\n", 10);
	printf("%u\n", 10);
	return 0;
} */

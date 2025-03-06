/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:07:03 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/25 22:45:02 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_type(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		count += ft_print_hex_min(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_print_hex_maj(va_arg(args, unsigned int));
	else if (c == '%')
		count += write(1, "%", 1);
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(args, int));
	else if (c == 'p')
		count += ft_print_hex_p(va_arg(args, void *));
	else
		return (0);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_find_type(format[i + 1], args);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	char ptr[] = "jnnjfjnfr";
	//printf("%d\n", printf("%s\n", "123456"));
	//ft_printf("%d\n", ft_printf("%s\n", "123456"));
	printf("\n");
	printf("\n");
	// ft_printf("%p\n", ptr);	
	return 0;
}*/

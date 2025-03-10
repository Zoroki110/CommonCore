/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:25:49 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/15 11:25:49 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr_fd_pf(char *s, int fd);
int		ft_putnbr_fd_pf(int n, int fd);
int		ft_putchar_pf(char c);
int		ft_print_hex(unsigned int n);
int		ft_printcaps_hex(unsigned int n);
int		ft_unsigned(int c);
int		ft_putunsigned(unsigned int n);
int		ft_pointer(void *ptr);
int		ft_hexptr(unsigned long long n);

#endif
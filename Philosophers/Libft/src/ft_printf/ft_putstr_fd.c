/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:22:17 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/30 12:42:11 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_pf(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd_pf("(null)", 1));
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

/*
int main()
{
	char str[] = "HELLO";
	ft_putstr_fd(str, 1);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:49:09 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 17:04:56 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int num, int min_count, int max_count)
{
	if (min_count == 1)
		num = -num;
	if ((min_count > 0 && max_count > 0) || min_count > 1 || max_count > 1)
		num = 0;
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min_count;
	int	max_count;
	int	num;

	i = 0;
	min_count = 0;
	max_count = 0;
	num = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			min_count++;
		if (str[i] == '+')
			max_count++;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		num = (num * 10) + (str[i++] - 48);
	num = ft_sign(num, min_count, max_count);
	return (num);
}
/*
int main()
{
	char str[] = "-27372833";
	int res = ft_atoi(str);

	printf("Mon atoi : %d\n", res);
	printf("Atoi fonction : %d\n", atoi(str));
}
*/

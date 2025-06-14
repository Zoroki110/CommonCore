/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 10:45:46 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/14 11:04:06 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	convert_digits(const char *str, int *i, long *result, int *error)
{
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
		{
			*error = 1;
			return (0);
		}
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (1);
}

int	ft_atoi_safe(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	*error = 0;
	sign = handle_sign(str, &i);
	if (!convert_digits(str, &i, &result, error))
		return (0);
	if (result * sign > INT_MAX || result * sign < INT_MIN)
	{
		*error = 1;
		return (0);
	}
	return ((int)(result * sign));
}

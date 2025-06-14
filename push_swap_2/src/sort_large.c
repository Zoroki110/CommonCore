/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:20:26 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/14 10:58:55 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num >> bits)
		bits++;
	return (bits);
}

void	radix_sort_optimized(t_data *data)
{
	int	bit;
	int	max_bits;
	int	size;
	int	i;

	size = data->size_a;
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((data->stack_a->index >> bit) & 1) == 0)
				pb(data, 1);
			else
				ra(data, 1);
			i++;
		}
		while (data->size_b > 0)
			pa(data, 1);
		bit++;
	}
}

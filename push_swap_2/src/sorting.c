/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:17:58 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 09:18:02 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_data *data)
{
	if (data->size_a <= 1)
		return ;
	else if (data->size_a == 2)
	{
		if (data->stack_a->value > data->stack_a->next->value)
			sa(data, 1);
	}
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a <= 5)
		sort_five(data);
	else
		radix_sort(data);
}

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->index;
	second = data->stack_a->next->index;
	third = data->stack_a->next->next->index;
	if (first > second && second < third && first < third)
		sa(data, 1);
	else if (first > second && second > third)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (first > second && second < third && first > third)
		ra(data, 1);
	else if (first < second && second > third && first < third)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (first < second && second > third && first > third)
		rra(data, 1);
}

void	sort_five(t_data *data)
{
	int	min_pos;

	while (data->size_a > 3)
	{
		min_pos = find_position(data->stack_a, get_min_index(data->stack_a));
		if (min_pos <= data->size_a / 2)
		{
			while (data->stack_a->index != get_min_index(data->stack_a))
				ra(data, 1);
		}
		else
		{
			while (data->stack_a->index != get_min_index(data->stack_a))
				rra(data, 1);
		}
		pb(data, 1);
	}
	sort_three(data);
	while (data->size_b > 0)
		pa(data, 1);
}

void	radix_sort(t_data *data)
{
	int	bit;
	int	max_bits;
	int	size;
	int	i;

	max_bits = 0;
	size = data->size_a;
	while ((size - 1) >> max_bits)
		max_bits++;
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

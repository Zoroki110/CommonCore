/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:20:12 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/14 10:59:26 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_min_to_b(t_data *data)
{
	int	min_index;
	int	min_pos;

	min_index = get_min_index(data->stack_a);
	min_pos = find_position(data->stack_a, min_index);
	if (min_pos <= data->size_a / 2)
	{
		while (data->stack_a->index != min_index)
			ra(data, 1);
	}
	else
	{
		while (data->stack_a->index != min_index)
			rra(data, 1);
	}
	pb(data, 1);
}

void	sort_four(t_data *data)
{
	push_min_to_b(data);
	sort_three(data);
	pa(data, 1);
}

void	sort_five_optimized(t_data *data)
{
	push_min_to_b(data);
	sort_four(data);
}

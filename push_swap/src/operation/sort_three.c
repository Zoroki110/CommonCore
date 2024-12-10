/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:23:20 by toikirouill       #+#    #+#             */
/*   Updated: 2024/12/10 22:08:34 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;
	
	biggest_node = max_stack(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
						 t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:22 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/11 11:05:49 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = cheapest_is(*a);
	if (cheapest_node->median_sup && cheapest_node->target_node->median_sup)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->median_sup)
		&& !(cheapest_node->target_node->median_sup))
		reverse_rotate_both(a, b, cheapest_node);
	rotate_stack(a, cheapest_node, 'a');
	rotate_stack(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

static void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	rotate_stack(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

static void	min_top(t_stack_node **a)
{
	while ((*a)->nbr != min_stack(*a)->nbr)
	{
		if (min_stack(*a)->median_sup)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_size(*a);
	if (len-- > 3 && !is_stack_sorted(*a))
		pb(b, a, true);
	if (len-- > 3 && !is_stack_sorted(*a))
		pb(b, a, true);
	while (len-- > 3 && !is_stack_sorted(*a))
	{
		define_node_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		define_node_b(*a, *b);
		push_b_to_a(a, b);
	}
	current_index(*a);
	min_top(a);
}

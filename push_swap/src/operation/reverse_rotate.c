/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:33:58 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/10 22:36:25 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
    t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void rra(t_stack_node **a, bool show)
{
    reverse_rotate(a);
    if (show)
        ft_printf("rra\n");
}

void rrb(t_stack_node **b, bool show)
{
    reverse_rotate(b);
    if (show)
        ft_printf("rrb\n");        
}

void	rrr(t_stack_node **a, t_stack_node **b, bool show)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (show)
		ft_printf("rrr\n");
}
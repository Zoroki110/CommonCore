/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:03:49 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/10 22:36:44 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void rotate(t_stack_node **stack)
{
    t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void    ra(t_stack_node **a, bool show)
{
    rotate(a);
    if (show)
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool show)
{
    rotate(b);
    if (show)
        ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool show)
{
    rotate(a);
    rotate(b);
    if (show)
        ft_printf("rr\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:33:58 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/09 11:09:41 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
    t_stack_node *last_node;
    t_stack_node *second_last_node;

    if (!*stack || !(*stack)->next)
        return ;
    last_node = ft_last_node(*stack);
    second_last_node = last_node->prev;
    second_last_node->next = NULL;
    last_node->prev = NULL;
    last_node->next = (*stack);
    (*stack)->prev = last_node;
    *stack = last_node;
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
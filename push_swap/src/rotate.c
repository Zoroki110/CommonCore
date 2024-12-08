/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:03:49 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/08 13:21:08 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void rotate(t_stack_node **stack)
{
    t_stack_node *first_node;
    t_stack_node *last_node;
    
    if (!*stack || !(*stack)->next)
        return ;
    first_node = *stack;
    last_node = ft_lstlast(*stack);
    *stack = first_node->next;
    (*stack)->prev = NULL;
    first_node->next = NULL;
    first_node->prev = last_node;
    last_node->next = first_node;
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
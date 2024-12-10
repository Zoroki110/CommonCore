/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:44:00 by toikirouill       #+#    #+#             */
/*   Updated: 2024/12/10 22:14:48 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void    current_index(t_stack_node *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return;
    median = stack_size(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->median_sup = true;
        else
            stack->median_sup = false;
        stack = stack->next;
        ++i;
    }
}

static void set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *current_b;
    t_stack_node    *target_node;
    long            best_match_index;
    
    while (a)
    {
        best_match_index = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            if (current_b->nbr < a->nbr 
                && current_b->nbr > best_match_index)
            {
                best_match_index = current_b->nbr;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == LONG_MIN)
            a->target_node = max_stack(b);
        else
            a->target_node = target_node;
        a = a->next;
    }
}  

static void min_rotate_a(t_stack_node *a, t_stack_node *b)
{
    int len_a;
    int len_b;

    len_a = stack_size(a);
    len_b = stack_size(b);
    while (a)
    {
        a->cost_to_push = a->index;
        if(!(a->median_sup))
            a->cost_to_push = len_a - (a->index);
        if (a->target_node->median_sup)
            a->cost_to_push += a->target_node->index;
        else
            a->cost_to_push += len_b - (a->target_node->index);
        a = a->next;
    }
}

void    set_cheapest(t_stack_node *stack)
{
    long    cheapest;
    t_stack_node    *cheapest_node;

    if (!stack)
        return ;
    cheapest = LONG_MAX;
    while (stack)
    {
        if (stack->cost_to_push < cheapest)
        {
            cheapest = stack->cost_to_push;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}
void    define_node_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    min_rotate_a(a, b);
    set_cheapest(a);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:54:00 by toikirouill       #+#    #+#             */
/*   Updated: 2024/12/10 22:14:52 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void set_target_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *current;
    t_stack_node    *target_node;
    long            best_match_index;

    while (b)
    {
        best_match_index = LONG_MAX;
        current = a;
        while (current)
        {
            if (current->nbr > b->nbr && current->nbr < best_match_index)
            {
                best_match_index = current->nbr;
                target_node = current;
            }
            current = current->next;
        }
        if (best_match_index == LONG_MAX)
            b->target_node = min_stack(a);
        else 
            b->target_node = target_node;
        b = b->next;
    }
}

void    define_node_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}

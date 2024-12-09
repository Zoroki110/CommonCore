/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:51:19 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/09 11:08:57 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void push(t_stack_node ** dest, t_stack_node **src)
{
    t_stack_node *tmp;
    
    if (!*src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    tmp->prev = NULL;
    if (!*dest)
    {
        *dest = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = *dest;
        tmp->next->prev = tmp;
        *dest = tmp;
    }
}

void    pa(t_stack_node **a, t_stack_node **b, bool show)
{
    push(a, b);
    if (show)
        ft_printf("pa\n");
}

void    pb(t_stack_node **b, t_stack_node **a, bool show)
{
    push(b , a);
    if (show)
        ft_printf("pb\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:25 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/11 11:05:03 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a, bool show)
{
	swap(a);
	if (show)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool show)
{
	swap(b);
	if (show)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool show)
{
	swap(a);
	swap(b);
	if (show)
		ft_printf("ss\n");
}

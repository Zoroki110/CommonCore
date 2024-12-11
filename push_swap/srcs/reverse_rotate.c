/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:31 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/11 11:04:33 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool show)
{
	reverse_rotate(a);
	if (show)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool show)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_define.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:32:03 by toikirouill       #+#    #+#             */
/*   Updated: 2024/12/10 22:20:31 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static long ft_atol(const char *str)
{
	long result;
	int signe;

	result = 0;
	signe = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - 48);
	return (result * signe);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;
	
	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;	
	}
}

void	define_stack_a(t_stack_node **a, char **av)
{
	long	n;
	int		i;
	
	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			ft_free(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_free(a);
		if (duplicate_error(*a, (int)n))
			ft_free(a);
		append_node(a, (int)n);
		i++;
	}
}

t_stack_node	*cheapest_is(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_stack(t_stack_node **stack, t_stack_node *top_node,
						char name_of_stack)
{
	while (*stack != top_node)
	{
		if (name_of_stack == 'a')
		{
			if (top_node->median_sup)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (name_of_stack == 'b')
		{
			if (top_node->median_sup)
				rb(stack, true);
			else
				rrb(stack, false);
		}
	}
}

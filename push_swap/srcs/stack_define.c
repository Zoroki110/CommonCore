/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_define.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:32:03 by toikirouill       #+#    #+#             */
/*   Updated: 2024/12/11 11:03:50 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		signe;

	result = 0;
	signe = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
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
				rrb(stack, true);
		}
	}
}

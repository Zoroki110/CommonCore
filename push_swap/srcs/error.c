/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:54:28 by toikirouill       #+#    #+#             */
/*   Updated: 2024/12/11 11:04:15 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	syntax_error(char *c)
{
	if (!(*c == '+' || *c == '-' || (*c >= '0' && *c <= '9')))
		return (1);
	if ((*c == '+' || *c == '-') && !(c[1] >= '0' && c[1] <= '9'))
		return (1);
	while (*++c)
	{
		if (!(*c >= '0' && *c <= '9'))
			return (1);
	}
	return (0);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_free(t_stack_node **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

int	duplicate_error(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

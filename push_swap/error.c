/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:54:28 by toikirouill       #+#    #+#             */
/*   Updated: 2024/12/10 22:19:07 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int syntax_error(char *c)
{
    if (!(*c == '-' || *c == '+' || (*c >= '0' && *c <= '9')))
        return (1);
    if ((*c == '-' || *c == '+') && !(c[1] >= '0' && c[1] <= '9'))
        return (1);
    while (*++c)
    {
        if (!(*c >= '0' && *c <= '9'))
            return (1);
    }
    return (0);
}
void    ft_free_stack(t_stack_node **stack)
{
    t_stack_node    *temp;
    t_stack_node    *current;

    if (!stack)
        return ;
    current = *stack;
    while (*stack)
    {
        temp = current->next;
        current->nbr = 0;
        free(current);
        current = temp;
    }
    *stack = NULL;
}

void    ft_free(t_stack_node **a)
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

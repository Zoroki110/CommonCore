/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:58:39 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/11 11:13:27 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
void	print_stack(t_stack_node *stack)
{
	t_stack_node	*current;

	if (!stack)
	{
		printf("Stack is empty\n");
		return ;
	}
	current = stack;
	while (current)
	{
		printf("%d\n", current->nbr);
		current = current->next;
	}
}
	printf("Sorted stack A:\n");
	print_stack(a);
*/

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	define_stack_a(&a, av + 1);
	if (!is_stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, true);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:15:37 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 09:15:40 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_data *data, int print)
{
	swap_stack(&data->stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_data *data, int print)
{
	swap_stack(&data->stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_data *data, int print)
{
	swap_stack(&data->stack_a);
	swap_stack(&data->stack_b);
	if (print)
		ft_printf("ss\n");
}

void	pa(t_data *data, int print)
{
	push_stack(&data->stack_b, &data->stack_a);
	data->size_a++;
	data->size_b--;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_data *data, int print)
{
	push_stack(&data->stack_a, &data->stack_b);
	data->size_a--;
	data->size_b++;
	if (print)
		ft_printf("pb\n");
}

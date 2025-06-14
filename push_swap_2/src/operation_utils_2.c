/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:16:51 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/14 10:29:14 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(t_data *data, int print)
{
	rotate_stack(&data->stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_data *data, int print)
{
	rotate_stack(&data->stack_a);
	rotate_stack(&data->stack_b);
	if (print)
		ft_printf("rr\n");
}

void	rra(t_data *data, int print)
{
	reverse_rotate_stack(&data->stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_data *data, int print)
{
	reverse_rotate_stack(&data->stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_data *data, int print)
{
	reverse_rotate_stack(&data->stack_a);
	reverse_rotate_stack(&data->stack_b);
	if (print)
		ft_printf("rrr\n");
}

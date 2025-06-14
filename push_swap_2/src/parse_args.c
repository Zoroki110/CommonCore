/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 10:47:09 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/14 11:04:12 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	return (data);
}

int	process_argument(t_data *data, char *arg)
{
	t_stack	*new_node;
	int		value;
	int		error;

	if (!is_valid_number(arg))
		return (0);
	value = ft_atoi_safe(arg, &error);
	if (error)
		return (0);
	new_node = ft_stacknew(value);
	if (!new_node)
		return (0);
	ft_stackadd_back(&data->stack_a, new_node);
	data->size_a++;
	return (1);
}

t_data	*parse_args(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = init_data();
	if (!data)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!process_argument(data, argv[i]))
		{
			free_data(data);
			return (NULL);
		}
		i++;
	}
	if (has_duplicates(data->stack_a))
	{
		free_data(data);
		return (NULL);
	}
	assign_indices(data->stack_a);
	return (data);
}

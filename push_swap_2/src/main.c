/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:15:00 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/12 09:15:05 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = parse_args(argc, argv);
	if (!data)
		ft_error();
	if (is_sorted(data->stack_a))
	{
		free_data(data);
		return (0);
	}
	sort_stack(data);
	free_data(data);
	return (0);
}

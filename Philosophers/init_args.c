/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:43:57 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/06 12:25:33 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int ac, char *av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (ft_atoi(av[1] < 1))
	{
		printf("Error: not enough philosophers\n");
		return (1);
	}
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3] < 60) || ft_atoi(av[4]) < 60)
	{
		printf("Error : time must be at least 60ms\n");
		return (1);
	}
	if (ac == 6 && ft_atoi(av[5]) < 1)
	{
		printf("Error : amount to eat must ve at least 1\n");
		return (1);
	}
	return (0);
}

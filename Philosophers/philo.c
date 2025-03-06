/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:54:28 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/06 12:25:48 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *av)
{
	t_rules			rules;
	pthread_mutex_t *forks;
	t_philo 		*philo;
	
	int dead = 0;
	if (!init_args(ac, av))
		return (1);
	if (!init_simulation(&rules, &forks, &philo, &dead))
		return (1);
	(void)ac;
	(void)av;
	return (0);
}

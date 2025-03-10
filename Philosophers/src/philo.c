/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:54:28 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/10 15:53:10 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
	t_rules			rules;
	pthread_mutex_t *forks;
	t_philo 		*philo;
	
	int dead = 0;
	if (init_args(&rules, ac, av) == 1)
		return (1);
	if (init_simulation(&rules, &forks, &philo, dead) == 1)
		return (1);
	//start_simulation(philo, rules.nb_philo);
	// printf("check philo%d\n", philo[0].dead);
	(void)ac;
	(void)av;
	return (0);
}
 
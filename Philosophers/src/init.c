/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:13:28 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/10 13:06:44 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(t_rules *rules, pthread_mutex_t **forks)
{
	int	i;

	*forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if (!*forks)
		return (1);
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(*forks)[i]);
			free(*forks);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_write_lock(pthread_mutex_t **write_lock)
{
	*write_lock = malloc(sizeof(pthread_mutex_t));
	if (!*write_lock)
		return (1);
	if (pthread_mutex_init(*write_lock, NULL) != 0)
	{
		free(*write_lock);
		return (1);
	}
	return (0);
}

void	assign_philo_data(t_philo *philo, int i, long start_time)
{
	philo->id = i + 1;
	philo->meal_eaten = 0;
	philo->last_eat_time = start_time;
	philo->start_time = start_time;
}

int	init_philos(t_philo **philos, t_rules *rules,
		pthread_mutex_t *forks, t_shared *shared)
{
	int		i;
	long	start_time;

	*philos = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!*philos)
		return (0);
	start_time = get_time();
	i = 0;
	while (i < rules->nb_philo)
	{
		assign_philo_data(&(*philos)[i], i, start_time);
		(*philos)[i].left_fork = &forks[i];
		(*philos)[i].right_fork = &forks[(i + 1) % rules->nb_philo];
		(*philos)[i].rules = rules;
		(*philos)[i].dead = shared->dead;
		(*philos)[i].write_lock = shared->write_lock;
		i++;
	}
	return (0);
}

int	init_simulation(t_rules *rules, pthread_mutex_t **forks,
		t_philo **philos, int dead)
{
	t_shared	shared;

	shared.dead = dead;
	printf("nb philo -> %d\n", rules->nb_philo);
	if (init_forks(rules, forks) == 1)
		return (0);
	if (init_write_lock(&shared.write_lock) == 1)
	{
		free(*forks);
		return (0);
	}
	// printf("ici\n");
	// printf("lala\n");
	if (init_philos(philos, rules, *forks, &shared) == 1)
	{
		pthread_mutex_destroy(shared.write_lock);
		free(shared.write_lock);
		cleanup_forks(*forks, rules->nb_philo);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:36 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/13 14:33:55 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_all_ate(t_philo *philo, int all_ate)
{
	if (philo[0].rules->amount_to_eat > 0 && all_ate)
	{
		pthread_mutex_lock(philo[0].write_lock);
		*(philo[0].dead) = 1;
		pthread_mutex_unlock(philo[0].write_lock);
		return (1);
	}
	return (0);
}

void	monitor_simulation(t_philo *philo)
{
	int		i;
	int		all_ate;
	long	current_time;

	usleep(1000);
	while (1)
	{
		i = 0;
		all_ate = 1;
		while (i < philo[0].rules->nb_philo)
		{
			current_time = get_time();
			pthread_mutex_lock(philo[i].meal_lock);
			if (check_philosopher_death(philo, i, current_time))
				return ;
			if (philo[i].rules->amount_to_eat > 0
				&& philo[i].meal_eaten < philo[i].rules->amount_to_eat)
				all_ate = 0;
			pthread_mutex_unlock(philo[i].meal_lock);
			i++;
		}
		if (check_all_ate(philo, all_ate))
			return ;
		usleep(1000);
	}
}

void	join_threads(t_philo *philo, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
		pthread_join(philo[i].thread, NULL);
}

void	cleanup_mutexes(pthread_mutex_t *forks, pthread_mutex_t *meal_locks,
						t_philo *philo, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&meal_locks[i]);
		free(philo[i].meal_lock);
	}
}

void	cleanup_simulation(t_philo *philo, pthread_mutex_t *forks)
{
	int				i;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_locks;
	int				num_philos;

	write_lock = philo[0].write_lock;
	num_philos = philo[0].rules->nb_philo;
	meal_locks = malloc(sizeof(pthread_mutex_t) * num_philos);
	i = -1;
	while (++i < num_philos)
		meal_locks[i] = *(philo[i].meal_lock);
	join_threads(philo, num_philos);
	cleanup_mutexes(forks, meal_locks, philo, num_philos);
	pthread_mutex_destroy(write_lock);
	free(write_lock);
	free(meal_locks);
	free(forks);
	free(philo);
}

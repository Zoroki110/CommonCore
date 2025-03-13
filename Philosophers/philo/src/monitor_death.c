/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:25:50 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/13 13:48:39 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*death_monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	int		all_eaten;

	philo = (t_philo *)arg;
	usleep(5000);
	while (1)
	{
		i = -1;
		all_eaten = 1;
		while (i++ < philo->rules->nb_philo)
		{
			if (check_death(&philo[i]))
			{
				dead_announce(&philo[i]);
				return (NULL);
			}
			if (!is_philo_full(&philo[i]))
				all_eaten = 0;
		}
		if (all_ate(&philo[i], all_eaten))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	long	time_last_eat;

	if (*(philo->dead) == 1)
		return (0);
	pthread_mutex_lock(philo->meal_lock);
	time_last_eat = philo->last_eat_time;
	pthread_mutex_unlock(philo->meal_lock);
	if (time_last_eat > philo->rules->time_to_die)
		return (0);
	return (1);
}

void	dead_announce(t_philo *philo)
{
	long	current_time;

	current_time = get_time();
	pthread_mutex_lock(philo->write_lock);
	if (!philo->dead)
	{
		*(philo->dead) = 1;
		printf("%ld %d died\n", current_time - philo->start_time, philo->id);
	}
	pthread_mutex_unlock(philo->write_lock);
}

int	is_philo_full(t_philo *philo)
{
	int	meal_eaten;

	if (philo->rules->amount_to_eat <= 0)
		return (0);
	pthread_mutex_lock(philo->meal_lock);
	meal_eaten = philo->meal_eaten;
	pthread_mutex_unlock(philo->meal_lock);
	if (meal_eaten >= philo->meal_eaten)
		return (0);
	return (1);
}

int	all_ate(t_philo *philos, int all_ate)
{
	if (philos[0].rules->amount_to_eat <= 0)
		return (0);
	if (all_ate)
	{
		pthread_mutex_lock(philos[0].write_lock);
		if (!(philos[0].dead))
			*(philos[0].dead) = 1;
		pthread_mutex_unlock(philos[0].write_lock);
		return (1);
	}
	return (0);
}

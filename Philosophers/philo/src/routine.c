/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:22:06 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/13 14:31:02 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	int		should_continue;

	philo = (t_philo *)arg;
	if (philo->rules->nb_philo == 1)
	{
		single_philo_fork(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(philo->rules->time_to_eat * 0.5 * 1000);
	while (philosopher_should_continue(philo, &should_continue))
	{
		if (!take_forks(philo))
			break ;
		if (!eat(philo))
			break ;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (!is_sleep(philo))
			break ;
		print_status(philo, "is thinking");
		usleep(200);
	}
	return (NULL);
}

int	lock_forks(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->write_lock);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(first);
		return (0);
	}
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(second);
	print_status(philo, "has taken a fork");
	return (1);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	pthread_mutex_lock(philo->write_lock);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->write_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->write_lock);
	if (philo->left_fork <= philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	return (lock_forks(philo, first_fork, second_fork));
}

int	eat(t_philo *philo)
{
	int	should_continue;

	pthread_mutex_lock(philo->write_lock);
	should_continue = !(*(philo->dead));
	pthread_mutex_unlock(philo->write_lock);
	if (!should_continue)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_status(philo, "is eating");
	pthread_mutex_lock(philo->meal_lock);
	philo->last_eat_time = get_time();
	philo->meal_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	precise_sleep(philo->rules->time_to_eat);
	return (1);
}

int	is_sleep(t_philo *philo)
{
	int	should_continue;

	pthread_mutex_lock(philo->write_lock);
	should_continue = !(*(philo->dead));
	pthread_mutex_unlock(philo->write_lock);
	if (!should_continue)
		return (0);
	print_status(philo, "is sleeping");
	precise_sleep(philo->rules->time_to_sleep);
	return (1);
}

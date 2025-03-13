/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:19:19 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/13 14:32:07 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	precise_sleep(long milliseconds)
{
	long	start_time;
	long	current_time;

	start_time = get_time();
	while (1)
	{
		current_time = get_time();
		if (current_time - start_time >= milliseconds)
			break ;
		usleep(100);
	}
}

int	philosopher_should_continue(t_philo *philo, int *should_continue)
{
	pthread_mutex_lock(philo->write_lock);
	*should_continue = !(*(philo->dead));
	pthread_mutex_unlock(philo->write_lock);
	return (*should_continue);
}

int	check_philosopher_death(t_philo *philo, int i, long current_time)
{
	if ((current_time - philo[i].last_eat_time) > philo[i].rules->time_to_die)
	{
		pthread_mutex_lock(philo[i].write_lock);
		printf("%ld %d died\n", current_time - philo[i].start_time,
			philo[i].id);
		*(philo[i].dead) = 1;
		pthread_mutex_unlock(philo[i].write_lock);
		pthread_mutex_unlock(philo[i].meal_lock);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:22:06 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/11 14:12:57 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *philosopher_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if (philo->rules->nb_philo == 1)
	{
		single_philo_fork(philo);
		return (NULL);
	}
    if (philo->id % 2 == 0)
        usleep(philo->rules->time_to_eat * 0.5 * 1000);
    while (!(philo->dead))
    {
        if (!take_forks(philo))
            break;
        if (!eat(philo))
            break;
        pthread_mutex_unlock(philo->left_fork);
    	pthread_mutex_unlock(philo->right_fork);
        if (!is_sleep(philo))
            break;
        print_status(philo, "is thinking");
        usleep(200);
    }
    return (NULL);
}

int	take_forks(t_philo *philo)
{
    if (philo->dead == 1)
        return (0);
    pthread_mutex_lock(philo->left_fork);
    print_status(philo, "has taken a fork");
    if (philo->dead == 1)
    {
        pthread_mutex_unlock(philo->left_fork);
        return (0);
    }
    pthread_mutex_lock(philo->right_fork);
    print_status(philo, "has taken a fork"); 
    return (1);
}


int	eat(t_philo *philo)
{
    if (philo->dead == 1)
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

int    is_sleep(t_philo *philo)
{
    if (philo->dead == 1)
        return (0);
    print_status(philo, "is sleeping");
    precise_sleep(philo->rules->time_to_sleep);
    return (1);
}

void    precise_sleep(long milliseconds)
{
    long    start_time;
    long    current_time;
    
    start_time = get_time();
    while (1)
    {
        current_time = get_time();
        if (current_time - start_time >= milliseconds)
            break;
        usleep(100);
    }
}

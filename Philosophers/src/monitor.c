/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:36 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/11 15:20:10 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    monitor_simulation(t_philo *philo)
{
    int     i;
    int     all_ate;
    long    current_time;
    
    while (1)
    {
        i = 0;
        all_ate = 1;
        
        while (i < philo[0].rules->nb_philo)
        {
            current_time = get_time();
            pthread_mutex_lock(philo[i].meal_lock);
            if ((current_time - philo[i].last_eat_time) > 
                philo[i].rules->time_to_die)
            {
                pthread_mutex_lock(philo[i].write_lock);
                printf("%ld %d died\n", 
                       current_time - philo[i].start_time, 
                       philo[i].id);
            	(philo[i].dead) = 1;
                pthread_mutex_unlock(philo[i].write_lock);
                pthread_mutex_unlock(philo[i].meal_lock);
                return;
            }
            pthread_mutex_unlock(philo[i].meal_lock);
            pthread_mutex_lock(philo[i].meal_lock);
            if (philo[i].rules->amount_to_eat > 0 && 
                philo[i].meal_eaten < philo[i].rules->amount_to_eat)
                all_ate = 0;
            pthread_mutex_unlock(philo[i].meal_lock);
            
            i++;
        }
        if (philo[0].rules->amount_to_eat > 0 && all_ate)
        {
            pthread_mutex_lock(philo[0].write_lock);
            printf("All philosophers have eaten %d meals. Simulation complete.\n",
                   philo[0].rules->amount_to_eat);
            (philo[0].dead) = 1;
            pthread_mutex_unlock(philo[0].write_lock);
            return;
        }
        usleep(1000);
    }
}

void    cleanup_simulation(t_philo *philo, pthread_mutex_t *forks)
{
	int             i;
	pthread_mutex_t *write_lock;
	pthread_mutex_t *meal_locks;
	int             num_philos;
	t_rules         *rules;
	
	// Save references before freeing
	rules = philo[0].rules;
	num_philos = rules->nb_philo;
	write_lock = philo[0].write_lock;
	
	// Allocate temporary array for meal locks
	meal_locks = malloc(sizeof(pthread_mutex_t) * num_philos);
	
	// Copy meal locks to temporary array
	i = 0;
	while (i < num_philos)
	{
		meal_locks[i] = *(philo[i].meal_lock);
		i++;
	}
	
	// Wait for all philosopher threads to finish
	i = 0;
	while (i < num_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	
	// Destroy all mutexes
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&meal_locks[i]);
		i++;
	}
	
	// Destroy write lock mutex
	pthread_mutex_destroy(write_lock);
	
	// Free all allocated memory
	free(write_lock);
	free(meal_locks);
	free(forks);
	free(philo);
	
	printf("Resources cleaned up successfully.\n");
}
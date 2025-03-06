/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:13:28 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/06 13:46:26 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_simulation(t_rules *rules, pthread_mutex_t **forks, t_philo **philo,
				int *dead)
{
	i
}

// Initialize all resources for the simulation
int init_simulation(t_rules *rules, pthread_mutex_t **forks, t_philo **philos, int *dead_flag)
{
    pthread_mutex_t *write_lock;
    int i;
    
    // Allocate memory for forks (mutexes)
    *forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
    if (!*forks)
        return (0);
    
    // Allocate memory for write lock mutex
    write_lock = malloc(sizeof(pthread_mutex_t));
    if (!write_lock)
    {
        free(*forks);
        return (0);
    }
    
    // Initialize write lock mutex
    if (pthread_mutex_init(write_lock, NULL) != 0)
    {
        free(*forks);
        free(write_lock);
        return (0);
    }
    
    // Initialize each fork mutex
    i = 0;
    while (i < rules->nb_philo)
    {
        if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
        {
            // Cleanup already initialized mutexes
            while (--i >= 0)
                pthread_mutex_destroy(&(*forks)[i]);
            pthread_mutex_destroy(write_lock);
            free(*forks);
            free(write_lock);
            return (0);
        }
        i++;
    }
    
    // Allocate and initialize philosophers
    *philos = malloc(sizeof(t_philo) * rules->nb_philo);
    if (!*philos)
    {
        // Cleanup mutexes
        i = rules->nb_philo;
        while (--i >= 0)
            pthread_mutex_destroy(&(*forks)[i]);
        pthread_mutex_destroy(write_lock);
        free(*forks);
        free(write_lock);
        return (0);
    }
    
    // Setup each philosopher
    i = 0;
    while (i < rules->nb_philo)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].meals_eaten = 0;
        (*philos)[i].last_meal_time = get_time();
        (*philos)[i].rules = rules;
        (*philos)[i].dead_flag = dead_flag;
        (*philos)[i].write_lock = write_lock;
        (*philos)[i].left_fork = &(*forks)[i];
        (*philos)[i].right_fork = &(*forks)[(i + 1) % rules->nb_philo];
        (*philos)[i].start_time = get_time();
        i++;
    }
    
    return (1);
}
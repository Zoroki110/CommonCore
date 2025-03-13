/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:54:28 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/13 14:10:29 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	single_philo_fork(t_philo *philo)
{
	print_status(philo, "has taken a fork");
	while (!philo->dead)
		usleep(100);
}

void	single_philo_dead(t_philo *philo)
{
	usleep(philo[0].rules->time_to_die * 1000);
	*(philo[0].dead) = 1;
	printf("%ld %d died\n", get_time() - philo[0].start_time, 1);
}

void	print_thinking_status(t_philo *philo, int nb_philo)
{
	int	i;

	i = -1;
	while (++i < nb_philo)
	{
		if (i % 2 == 0)
		{
			pthread_mutex_lock(philo[i].write_lock);
			printf("%ld %d is thinking\n", get_time() - philo[i].start_time,
				philo[i].id);
			pthread_mutex_unlock(philo[i].write_lock);
		}
	}
}

void	start_simulation(t_philo *philo, int nb_philo)
{
	int		i;
	long	start_time;

	start_time = get_time();
	i = -1;
	while (++i < nb_philo)
	{
		philo[i].start_time = start_time;
		philo[i].last_eat_time = start_time;
	}
	i = -1;
	while (++i < nb_philo)
	{
		if (pthread_create(&(philo[i].thread), NULL, philosopher_routine,
				&philo[i]) != 0)
		{
			*(philo[0].dead) = 1;
			printf("Thread creation failed\n");
			return ;
		}
	}
	if (nb_philo == 1)
		return (single_philo_dead(&philo[0]));
	print_thinking_status(philo, nb_philo);
}
// void	start_simulation(t_philo *philo, int nb_philo)
// {
// 	int		i;
// 	long	start_time;

// 	start_time = get_time();
// 	i = 0;
// 	while (i < nb_philo)
// 	{
// 		philo[i].start_time = start_time;
// 		philo[i].last_eat_time = start_time;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < nb_philo)
// 	{
// 		if (pthread_create(&(philo[i].thread), NULL, philosopher_routine,
// 				&philo[i]) != 0)
// 		{
// 			*(philo[0].dead) = 1;
// 			printf("Thread creation failed\n");
// 			return ;
// 		}
// 		i++;
// 	}
// 	if (nb_philo == 1)
// 	{
// 		single_philo_dead(&philo[0]);
// 		return ;
// 	}
// 	i = 0;
// 	while (i < nb_philo)
// 	{
// 		if (i % 2 == 0)
// 		{
// 			pthread_mutex_lock(philo[i].write_lock);
// 			printf("%ld %d is thinking\n", get_time() - philo[i].start_time,
// 				philo[i].id);
// 			pthread_mutex_unlock(philo[i].write_lock);
// 		}
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	t_rules			rules;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	int				dead;

	dead = 0;
	if (init_args(&rules, ac, av) == 1)
		return (1);
	if (init_simulation(&rules, &forks, &philo, &dead) == 1)
		return (1);
	start_simulation(philo, rules.nb_philo);
	monitor_simulation(philo);
	cleanup_simulation(philo, forks);
	return (0);
}

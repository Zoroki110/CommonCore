/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:14:04 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/11 15:19:39 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/time.h>
# include <unistd.h>


typedef struct s_rules
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				amount_to_eat;
} t_rules;

typedef struct s_philo
{
	int				id;
	int				meal_eaten;
	long			last_eat_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*meal_lock;
	t_rules			*rules;
	int				start_time;
	int				dead;
	pthread_mutex_t	*write_lock;
} t_philo;

typedef struct s_shared
{
	pthread_mutex_t	*write_lock;
	int				dead;
}	t_shared;

//init_args.c
int			init_args(t_rules *rules, int ac, char **av);
long		get_time(void);
int			ft_atoi(const char *str);
void		print_status(t_philo *philo, char *status);

//init.c
int			init_philos(t_philo **philos, t_rules *rules,
				pthread_mutex_t *forks, t_shared *shared);
int			init_simulation(t_rules *rules, pthread_mutex_t **forks,
				t_philo **philos, int dead);
void		assign_philo_data(t_philo *philo, int i, long start_time);
int			init_write_lock(pthread_mutex_t **write_lock);
int			init_forks(t_rules *rules, pthread_mutex_t **forks);

//philo.c
void		single_philo_fork(t_philo *philo);

//monitor.c
void    cleanup_simulation(t_philo *philo, pthread_mutex_t *fork);
void    monitor_simulation(t_philo *philo);
//monitor_death.c
void		*death_monitor(void *arg);
int			check_death(t_philo *philo);
void		dead_announce(t_philo *philo);
int			is_philo_full(t_philo *philo);
int			all_ate(t_philo *philos, int all_ate);

//routine.c
void		*philosopher_routine(void *arg);
int			take_forks(t_philo *philo);
int			eat(t_philo *philo);
int			is_sleep(t_philo *philo);
void		precise_sleep(long milliseconds);

//free.c
void		cleanup_forks(pthread_mutex_t *forks, int num_philos);
#endif
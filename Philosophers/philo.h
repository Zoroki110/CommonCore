/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:14:04 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/06 13:44:54 by trouilla         ###   ########.fr       */
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
# include <sys/times.h>
# include <unistd.h>
# include "Libft/include/ft_printf.h"
# include "Libft/include/get_next_line.h"
# include "Libft/include/libft.h"

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
	long			last_eat;
	pthread_t		thread;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *meal_lock;
	t_rules			*rules;
	int				*dead;
} t_philo;

//init_args.c
int	init_args(int ac, char **av);

#endif
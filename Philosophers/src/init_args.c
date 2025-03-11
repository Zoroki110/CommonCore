/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:43:57 by trouilla          #+#    #+#             */
/*   Updated: 2025/03/11 10:17:54 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_args(t_rules *rules, int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (ft_atoi(av[1]) < 1)
	{
		printf("Error: not enough philosophers\n");
		return (1);
	}
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		printf("Error : time must be at least 60ms\n");
		return (1);
	}
	if (ac == 6 && ft_atoi(av[5]) < 1)
	{
		printf("Error : amount to eat must ve at least 1\n");
		return (1);
	}
	rules->nb_philo = ft_atoi(av[1]);
	return (0);
}

long get_time(void) 
{
   struct timeval tv;
   gettimeofday(&tv, NULL);
   return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}


void print_status(t_philo *philo, char *status)
{
   pthread_mutex_lock(philo->write_lock);
   if (!(philo->dead))
       printf("%ld %d %s\n", get_time() - philo->start_time, 
              philo->id, status);
   pthread_mutex_unlock(philo->write_lock);
}

static int	ft_sign(int num, int min_count, int max_count)
{
	if (min_count == 1)
		num = -num;
	if ((min_count > 0 && max_count > 0) || min_count > 1 || max_count > 1)
		num = 0;
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min_count;
	int	max_count;
	int	num;

	i = 0;
	min_count = 0;
	max_count = 0;
	num = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			min_count++;
		if (str[i] == '+')
			max_count++;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		num = (num * 10) + (str[i++] - 48);
	num = ft_sign(num, min_count, max_count);
	return (num);
}

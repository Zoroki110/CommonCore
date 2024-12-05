/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:05:29 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/03 10:11:26 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_filename(void)
{
	write(2, "Error, The FileName should be BER extension file\n", 49);
	exit(EXIT_FAILURE);
}

void	error_open(void)
{
	write(2, "Error trying open the file\n", 27);
	exit(EXIT_FAILURE);
}

void	error_size(t_map *map)
{
	write(2, "Error, Wrong size for the Map\n", 30);
	ft_free_array(map->array);
	ft_free_array(map->copy);
	exit(EXIT_FAILURE);
}

void	error_wall(t_map *map)
{
	write(2, "Error, Need Wall\n", 17);
	ft_free_array(map->array);
	ft_free_array(map->copy);
	exit(EXIT_FAILURE);
}

void	error_pec(t_map *map)
{
	write(2, "Error, Wrong element\n", 21);
	ft_free_array(map->array);
	ft_free_array(map->copy);
	exit(EXIT_FAILURE);
}

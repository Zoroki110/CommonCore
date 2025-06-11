/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:01:57 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/11 20:32:00 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void get_player_pos(t_game *g, int *x, int *y)
{
    int i, j;
    
    i = 0;
    while (i < g->height && g->map[i])
    {
        j = 0;
        while (j < g->width && g->map[i][j])
        {
            if (g->map[i][j] == 'P')
            {
                *x = j;
                *y = i;
                return;
            }
            j++;
        }
        i++;
    }
    static int last_x = -1, last_y = -1;
    if (last_x == -1 || last_y == -1)
    {
        i = 0;
        while (i < g->height && g->map[i])
        {
            j = 0;
            while (j < g->width && g->map[i][j])
            {
                if (g->map[i][j] == 'E')
                {
                    *x = j;
                    *y = i;
                    last_x = j;
                    last_y = i;
                    return;
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        *x = last_x;
        *y = last_y;
    }
}
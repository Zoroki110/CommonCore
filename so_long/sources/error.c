#include "so_long.h"

void    error_filename(void)
{
    write(2, "Error, The FileName should be BER extension file\n", 49);
    exit(EXIT_FAILURE);
}

void error_open(void)
{
    write(2, "Error trying open the file\n", 27);
    exit(EXIT_FAILURE);
}

void error_size(t_map *map)
{
    write(2, "Error, Wrong size for the Map\n", 30);
    ft_free_array(map->array, map->y);
    ft_free_array(map->copy, map->y);
    exit(EXIT_FAILURE);
}

void error_wall(t_map *map)
{
    write(2, "Error, Need Wall\n", 17);
    ft_free_array(map->array, map->y);
    ft_free_array(map->copy, map->y);
    exit(EXIT_FAILURE);
}

void error_PEC(t_map *map)
{
    write(2, "Error, Wrong element\n", 21);
    ft_free_array(map->array, map->y);
    ft_free_array(map->copy, map->y);
    exit(EXIT_FAILURE);
}
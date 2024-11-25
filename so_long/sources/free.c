#include "so_long.h"

int	ft_free_array(char **str, int i)
{
    while (i > 0)
        free(str[i--]);
    free(str);
    return (0);
}

void	ft_exit_free(t_map *map)
{
    if (map->array)
        free(map->array);
    if (map->copy)
        free(map->copy);
    if (map->line)
        free(map->line);
    if (map->file)
        free(map->file);
    exit(EXIT_FAILURE);
}
#include "so_long.h"

void map_array(t_map *map)
{
    int fd;

    map->y = 0;
    map->line = "";
    map->file = NULL;
    fd = open(map->filename, O_RDONLY);
    if (fd == -1)
        error_open();
    while (map->line)
    {
        map->line = get_next_line(fd);
        if (map->line == NULL)
            break ;
        map->file = ft_strjoin(map->file, map->line);
        free(map->line);
        if (!map->file)
            ft_exit_free(map);
        map->y++;
    }
    close(fd);
    map->array = ft_split(map->file, '\n');
    map->copy = ft_split(map->file, '\n');
    if (!map->array || !map->copy)
        ft_exit_free(map);
    free(map->file);
}
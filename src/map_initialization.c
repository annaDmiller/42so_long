#include "so_long.h"

static char *form_map_line(int fd, char *map_line);

char    **map_init(char *map_addr)
{
//    char    **map;
    char    *map_line;
    int     fd;

    fd = open(map_addr, O_RDONLY);
    if  (fd == -1)
        error("Not able to open the file\n");
    map_line = NULL;
    map_line = form_map_line(fd, map_line);
    ft_printf("%s\n", map_line);
    free(map_line);
    return (NULL);
}

static char *form_map_line(int fd, char *map_line)
{
    char    *gnl;
    size_t  new_size;

    gnl = get_next_line(fd);
    if (!gnl && !map_line)
        error("Malloc error\n");
    if (!gnl)
        return (map_line);
    new_size = ft_strlen(map_line) + ft_strlen(gnl) + 1;
    map_line = str_realloc(map_line, new_size);
    if (!map_line)
    {
        free(gnl);
        error("Malloc error\n");
    }
    ft_strlcat(map_line, gnl, new_size);
    free(gnl);
    return (form_map_line(fd, map_line));
}
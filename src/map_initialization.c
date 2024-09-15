#include "so_long.h"

static char	*form_map_line(int fd, char *map_line);

char	**map_init(char *map_addr)
{
	char	**map;
	char	*map_line;
	int		fd;
	int		quan_c;

	fd = open(map_addr, O_RDONLY);
	if (fd < 0 || fd > 1024)
		error("Not able to open the file\n");
	map_line = NULL;
	map_line = form_map_line(fd, map_line);
	validate_letters(map_line);
	quan_c = validate_cep(map_line);
	map = ft_split(map_line, '\n');
	free(map_line);
	close(fd);
	if (!map)
		error("Malloc error: impossible to create map\n");
	validate_map_arr(map, quan_c);
	return (map);
}

static char	*form_map_line(int fd, char *map_line)
{
	char	*gnl;
	size_t	new_size;

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

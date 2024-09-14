#include "so_long.h"

static int	find_quan_y(char **map);

char	**create_temp_map(char **map)
{
	int		num_str;
	char	**temp_map;
	int		y;

	num_str = find_quan_y(map);
	temp_map = (char **) malloc((num_str + 1) * sizeof(char *));
	if (!temp_map)
	{
		ft_free_arr(map);
		error("Malloc error\n");
	}
	*temp_map = NULL;
	y = -1;
	while (++y < num_str)
	{
		temp_map[y] = ft_strdup(map[y]);
		if (!temp_map[y])
		{
			ft_free_arr(map);
			ft_free_arr(temp_map);
			error("Malloc error\n");
		}
	}
	temp_map[y] = NULL;
	return (temp_map);
}

static int	find_quan_y(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

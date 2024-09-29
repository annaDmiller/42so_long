#include "so_long.h"

static void	validate_rect(char **map);

static void	validate_size(char **map);

void	validate_map_arr(char **map, int quan_c)
{
	validate_rect(map);
	validate_border(map);
	validate_collect(map, quan_c);
	validate_size(map);
	return ;
}

static void	validate_rect(char **map)
{
	int		ind_s;
	size_t	len_str;
	size_t	len_first;

	ind_s = 1;
	len_first = ft_strlen(map[0]);
	while (map[ind_s])
	{
		len_str = ft_strlen(map[ind_s]);
		if (len_str != len_first)
			err_arr("Incorrect map: map isn't rectangular\n", map);
		ind_s++;
	}
	return ;
}

static void	validate_size(char **map)
{
	size_t	len_x;
	int		height_y;

	len_x = ft_strlen(*map);
	height_y = 0;
	while (map[height_y])
		height_y++;
	if (height_y > HEIGHT_MAX / 30 && len_x > LENGTH_MAX  / 30)
	{
		ft_free_arr(map);
		error("Incorrect map: max size of map is 64x34\n");
	}
	return ;
}

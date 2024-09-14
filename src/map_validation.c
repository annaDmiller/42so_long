#include "so_long.h"

static void	validate_rect(char **map);

static int	is_valid_let(char car);

int	validate_cep(char *map_line)
{
	int	ind;
	int	quan_e;
	int	quan_c;
	int	quan_p;

	ind = -1;
	quan_e = 0;
	quan_c = 0;
	quan_p = 0;
	while (map_line[++ind])
	{
		if (map_line[ind] == 'C')
			quan_c++;
		if (map_line[ind] == 'E')
			quan_e++;
		if (map_line[ind] == 'P')
			quan_p++;
	}
	if (quan_e != 1 || quan_p != 1 || quan_c < 1)
	{
		free(map_line);
		error("Incorrect map (check exit, player and collectibles)\n");
	}
	return (quan_c);
}

void	validate_letters(char *map_line)
{
	int	ind;

	ind = 0;
	while (map_line[ind])
	{
		if (is_valid_let(map_line[ind]))
		{
			free(map_line);
			error("Map error: invalid letters are in map\n");
		}
		ind++;
	}
	return ;
}

static int	is_valid_let(char car)
{
	if (car == '1' || car == '0' || car == 'E'
		|| car == 'C' || car == 'P' || car == '\n')
		return (0);
	return (1);
}

void	validate_map_arr(char **map, int quan_c)
{
	validate_rect(map);
	validate_border(map);
	validate_collect(map, quan_c);
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
		{
			ft_free_arr(map);
			error("Incorrect map: map isn't rectangular\n");
		}
		ind_s++;
	}
	return ;
}

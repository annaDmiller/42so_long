#include "so_long.h"

static void	validate_top_line(char **map);

static void	validate_middle(char **map);

static void	validate_bot_line(char **map);

void	validate_border(char **map)
{
	validate_top_line(map);
	validate_middle(map);
	validate_bot_line(map);
	return ;
}

static void	validate_top_line(char **map)
{
	int	ind_c;

	ind_c = -1;
	while (map[0][++ind_c])
	{
		if (map[0][ind_c] != '1')
		{
			ft_free_arr(map);
			error("Incorrect map: incorrect border\n");
		}
	}
	return ;
}

static void	validate_middle(char **map)
{
	int	ind_s;
	int	end_s;

	ind_s = 0;
	while (map[++ind_s])
	{
		if (!map[ind_s + 1])
			break ;
		end_s = ft_strlen(map[ind_s]);
		if (map[ind_s][0] != '1' || map[ind_s][end_s - 1] != '1')
		{
			ft_free_arr(map);
			error("Incorrect map: incorrect border\n");
		}
	}
	return ;
}

static void	validate_bot_line(char **map)
{
	int	ind_c;
	int	last_s;

	last_s = 0;
	while (map[last_s])
		last_s++;
	ind_c = -1;
	last_s--;
	while (map[last_s][++ind_c])
	{
		if (map[last_s][ind_c] != '1')
		{
			ft_free_arr(map);
			error("Incorrect map: incorrect border\n");
		}
	}
	return ;
}

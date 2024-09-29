/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_collectibles.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:40:28 by amelniko          #+#    #+#             */
/*   Updated: 2024/09/29 12:40:29 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fill_flood(char **map, int x, int y, int *quan_c);

static void	find_start(char **map, int *start_x, int *start_y);

void	validate_collect(char **map, int quan_c)
{
	int		quan_e;
	int		start_x;
	int		start_y;
	char	**copy_map;

	start_x = 0;
	start_y = 0;
	copy_map = create_temp_map(map);
	find_start(map, &start_x, &start_y);
	quan_e = fill_flood(copy_map, start_x, start_y, &quan_c);
	ft_free_arr(copy_map);
	if (quan_c != 0)
		err_arr("Incorrect map: inachievable collectibles\n", map);
	if (quan_e != 1)
		err_arr("Incorrect map: no way out\n", map);
	return ;
}

static void	find_start(char **map, int *start_x, int *start_y)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

static int	fill_flood(char **map, int x, int y, int *quan_c)
{
	int	quan_e;

	if (y < 0 || !map[y])
		return (0);
	if (x < 0 || !map[y][x])
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'N')
		return (0);
	if (map[y][x] == 'E')
	{
		map[y][x] = 'N';
		return (1);
	}
	if (map[y][x] == 'C')
		*quan_c = *quan_c - 1;
	map[y][x] = 'N';
	quan_e = 0;
	quan_e += fill_flood(map, x + 1, y, quan_c);
	quan_e += fill_flood(map, x - 1, y, quan_c);
	quan_e += fill_flood(map, x, y + 1, quan_c);
	quan_e += fill_flood(map, x, y - 1, quan_c);
	return (quan_e);
}

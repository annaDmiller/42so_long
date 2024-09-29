/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_letters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:40:39 by amelniko          #+#    #+#             */
/*   Updated: 2024/09/29 12:40:40 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:38:10 by amelniko          #+#    #+#             */
/*   Updated: 2024/09/29 12:38:10 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_items(t_total *tot, int x, int y);

void	draw_map(t_total *tot)
{
	int	x;
	int	y;

	y = 0;
	while (tot->map[y])
	{
		x = 0;
		while (tot->map[y][x])
		{
			if (tot->map[y][x] == '1')
				mlx_put_image_to_window(tot->mlx->mlx,
					tot->mlx->win, tot->img->wall->img, x * 30, y * 30);
			else
				mlx_put_image_to_window(tot->mlx->mlx,
					tot->mlx->win, tot->img->floor->img, x * 30, y * 30);
			if (tot->map[y][x] != '1' || tot->map[y][x] != '0')
				draw_items(tot, x, y);
			x++;
		}
		y++;
	}
	return ;
}

static void	draw_items(t_total *tot, int x, int y)
{
	if (tot->map[y][x] == 'C')
		mlx_put_image_to_window(tot->mlx->mlx, tot->mlx->win,
			tot->img->coll->img, x * 30, y * 30);
	if (tot->map[y][x] == 'P')
		mlx_put_image_to_window(tot->mlx->mlx, tot->mlx->win,
			tot->img->player->img, x * 30, y * 30);
	if (tot->map[y][x] == 'E')
		mlx_put_image_to_window(tot->mlx->mlx, tot->mlx->win,
			tot->img->exit->img, x * 30, y * 30);
	return ;
}

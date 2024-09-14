#include "so_long.h"

static void	draw_items(t_total *tot, int x, int y);

void	draw_map(t_total *tot)
{
	int	x;
	int	y;

	y = 0;
	while (y * 50 < HEIGHT && tot->map[y])
	{
		x = 0;
		while (x * 50 < LENGTH && tot->map[y][x])
		{
			if (tot->map[y][x] == '1')
				mlx_put_image_to_window(tot->mlx->mlx,
					tot->mlx->win, tot->img->wall->img, x * 50, y * 50);
			else
				mlx_put_image_to_window(tot->mlx->mlx,
					tot->mlx->win, tot->img->floor->img, x * 50, y * 50);
			if (tot->map[y][x] != '1' || tot->map[y][x] != '0')
				draw_items(tot, x, y);
			x++;
		}
		y++;
	}
	ft_printf("Number of steps: %u\n", g_steps);
	return ;
}

static void	draw_items(t_total *tot, int x, int y)
{
	if (tot->map[y][x] == 'C')
		mlx_put_image_to_window(tot->mlx->mlx, tot->mlx->win,
			tot->img->coll->img, x * 50 + 15, y * 50 + 15);
	if (tot->map[y][x] == 'P')
		mlx_put_image_to_window(tot->mlx->mlx, tot->mlx->win,
			tot->img->player->img, x * 50 + 3, y * 50 + 3);
	if (tot->map[y][x] == 'E')
		mlx_put_image_to_window(tot->mlx->mlx, tot->mlx->win,
			tot->img->exit->img, x * 50 + 3, y * 50 + 3);
	return ;
}

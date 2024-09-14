#include "so_long.h"

int	button_logic(int keycode, t_total *total)
{
	if (keycode == ESC)
	{
		ft_free_arr(*(total->map));
		mlx_destroy_window(total->mlx->mlx, total->mlx->win);
		exit(0);
	}
	return (0);
}

int	button_cross_logic(t_total *total)
{
	ft_free_arr(*(total->map));
	mlx_destroy_window(total->mlx->mlx, total->mlx->win);
	exit(0);
	return (0);
}

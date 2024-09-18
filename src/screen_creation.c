#include "so_long.h"

static void	window_init(t_total *tot);
static void	image_init(t_total *tot);

void	screen_logic(char **map)
{
	t_win		win;
	t_map_img	map_img;
	t_total		total;

	total.img = &map_img;
	total.mlx = &win;
	total.map = map;
	window_init(&total);
	image_init(&total);
	mlx_hook(win.win, 2, 1L << 0, button_logic, &total);
	mlx_hook(win.win, 17, 1L << 17, button_cross_logic, &total);
	draw_map(&total);
	mlx_loop(win.mlx);
}

static void	window_init(t_total *tot)
{
	size_t	len_x;
	int		height_y;

	len_x = ft_strlen(tot->map[0]);
	height_y = 0;
	while (tot->map[height_y])
		height_y++;
	tot->mlx->mlx = mlx_init();
	if (!tot->mlx->mlx)
		err_arr("Screen creation error\n", tot->map);
	tot->mlx->win = mlx_new_window(tot->mlx->mlx, len_x * 30, height_y * 30, "SO_LONG GAME");
	if (!tot->mlx->win)
	{
		mlx_destroy_display(tot->mlx->mlx);
		err_arr("Screen creation error\n", tot->map);
	}
	return ;
}

static void	image_init(t_total *tot)
{
	tot->img->coll = (t_img *) malloc(sizeof(t_img));
	tot->img->player = (t_img *) malloc(sizeof(t_img));
	tot->img->wall = (t_img *) malloc(sizeof(t_img));
	tot->img->floor = (t_img *) malloc(sizeof(t_img));
	tot->img->exit = (t_img *) malloc(sizeof(t_img));
	if (!tot->img->coll || !tot->img->player || !tot->img->wall
		|| !tot->img->floor || !tot->img->exit)
		err_screen("Malloc error\n", tot, 0);
	tot->img->coll->img = mlx_xpm_file_to_image(tot->mlx->mlx,
			"./cell/c.xpm", &(tot->img->coll->w), &(tot->img->coll->h));
	tot->img->player->img = mlx_xpm_file_to_image(tot->mlx->mlx,
			"./cell/p.xpm", &(tot->img->player->w), &(tot->img->player->h));
	tot->img->wall->img = mlx_xpm_file_to_image(tot->mlx->mlx,
			"./cell/1.xpm", &(tot->img->wall->w), &(tot->img->wall->h));
	tot->img->floor->img = mlx_xpm_file_to_image(tot->mlx->mlx,
			"./cell/0.xpm", &(tot->img->floor->w), &(tot->img->floor->h));
	tot->img->exit->img = mlx_xpm_file_to_image(tot->mlx->mlx,
			"./cell/e.xpm", &(tot->img->exit->w), &(tot->img->exit->h));
	if (!tot->img->coll->img || !tot->img->player->img || !tot->img->wall->img
		|| !tot->img->floor->img || !tot->img->exit->img)
		err_screen("Image error\n", tot, 1);
	return ;
}

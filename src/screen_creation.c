#include "so_long.h"

static void	window_init(t_win *win, char **map);
static void	image_init(t_map_img *map_img, t_win *win, char **map);

void	screen_logic(char **map)
{
	t_win		win;
	t_map_img	map_img;
	t_total		total;

	window_init(&win, map);
	image_init(&map_img, &win, map);
	total.img = &map_img;
	total.mlx = &win;
	total.map = map;
	mlx_hook(win.win, 2, 1L << 0, button_logic, &total);
	mlx_hook(win.win, 17, 1L << 17, button_cross_logic, &total);
	draw_map(&total);
	mlx_loop(win.mlx);
}

static void	window_init(t_win *win, char **map)
{
	size_t	len_x;
	int		height_y;

	len_x = ft_strlen(*map);
	height_y = 0;
	while (map[height_y])
		height_y++;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, len_x * 30, height_y * 30, "SO_LONG GAME");
	return ;
}

static void	image_init(t_map_img *map_img, t_win *win, char **map)
{
	map_img->coll = (t_img *) malloc(sizeof(t_img));
	map_img->player = (t_img *) malloc(sizeof(t_img));
	map_img->wall = (t_img *) malloc(sizeof(t_img));
	map_img->floor = (t_img *) malloc(sizeof(t_img));
	map_img->exit = (t_img *) malloc(sizeof(t_img));
	if (!map_img->coll || !map_img->player || !map_img->wall
		|| !map_img->floor || !map_img->exit)
	{
		ft_free_arr(map);
		free_map_img(map_img);
		error("Malloc error\n");
	}
	map_img->coll->img = mlx_xpm_file_to_image(win->mlx,
			"./textures/c.xpm", &(map_img->coll->w), &(map_img->coll->h));
	map_img->player->img = mlx_xpm_file_to_image(win->mlx,
			"./textures/p.xpm", &(map_img->player->w), &(map_img->player->h));
	map_img->wall->img = mlx_xpm_file_to_image(win->mlx,
			"./textures/1.xpm", &(map_img->wall->w), &(map_img->wall->h));
	map_img->floor->img = mlx_xpm_file_to_image(win->mlx,
			"./textures/0.xpm", &(map_img->floor->w), &(map_img->floor->h));
	map_img->exit->img = mlx_xpm_file_to_image(win->mlx,
			"./textures/e.xpm", &(map_img->exit->w), &(map_img->exit->h));
	return ;
}

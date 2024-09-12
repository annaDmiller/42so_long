#include "so_long.h"

static void    window_init(t_win *win);
static void image_init(t_img *img, t_win *win);

void    screen_logic(char **map)
{
    t_win   win;
    t_img   img;
    t_total total;

    window_init(&win);
    image_init(&img, &win);
    total.img = &img;
    total.mlx = &win;
    total.map = &map;
    mlx_hook(win.win, 2, 1L<<0, button_logic, &total);
    mlx_hook(win.win, 17, 1L<<17, button_cross_logic, &total);
    mlx_loop(win.mlx);
}

static void    window_init(t_win *win)
{
    win->mlx = mlx_init();
    win->win = mlx_new_window(win->mlx, LENGTH, HEIGHT, "SO_LONG");
    return ;
}

static void image_init(t_img *img, t_win *win)
{
    img->img = mlx_new_image(win->mlx, LENGTH - 100, HEIGHT - 50);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    return ;
}
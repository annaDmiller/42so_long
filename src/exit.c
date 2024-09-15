#include "so_long.h"

void    err_arr(char *mess, char **map)
{
    ft_free_arr(map);
    error(mess);
}

void    err_screen(char *mess, t_total *tot)
{
    ft_free_arr(tot->map);
    free_map_img(tot->img);
    error(mess);
}

void    succ_exit(char *mess, t_total *tot)
{
    ft_putstr_fd(mess, 1);
    ft_free_arr(tot->map);
    free_map_img(tot->img);
    mlx_destroy_window(tot->mlx->mlx, tot->mlx->win);
    mlx_destroy_display(tot->mlx->mlx);
    exit(0);
}
#include "so_long.h"

void	free_map_img(t_map_img *map_img, void *mlx, int check)
{
	if (check == 1)
	{
		mlx_destroy_image(mlx, map_img->coll->img);
		mlx_destroy_image(mlx, map_img->exit->img);
		mlx_destroy_image(mlx, map_img->floor->img);
		mlx_destroy_image(mlx, map_img->player->img);
		mlx_destroy_image(mlx, map_img->wall->img);
	}
	free(map_img->coll);
	free(map_img->exit);
	free(map_img->floor);
	free(map_img->player);
	free(map_img->wall);
	return ;
}

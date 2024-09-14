#include "so_long.h"

void	free_map_img(t_map_img *map_img)
{
	free(map_img->coll);
	free(map_img->exit);
	free(map_img->player);
	free(map_img->wall);
	free(map_img->floor);
	return ;
}

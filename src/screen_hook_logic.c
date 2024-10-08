#include "so_long.h"

int	button_logic(int keycode, t_total *total)
{
	if (keycode == ESC)
		succ_exit("Closed unfinished.\n", total);
	if (keycode == W || keycode == UP)
		player_move_up(total);
	if (keycode == S || keycode == DOWN)
		player_move_down(total);
	if (keycode == A || keycode == LEFT)
		player_move_left(total);
	if (keycode == D || keycode == RIGHT)
		player_move_right(total);
	return (0);
}

int	button_cross_logic(t_total *total)
{
	succ_exit("Closed unfinished.\n", total);
	return (0);
}

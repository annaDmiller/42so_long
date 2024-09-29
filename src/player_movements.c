/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:40:54 by amelniko          #+#    #+#             */
/*   Updated: 2024/09/29 12:46:52 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_total *tot)
{
	t_point	*play;
	int		check_coll;

	check_coll = -1;
	play = find_player(tot);
	if (play->x == -1)
		err_screen("Unknown error: impossible to find player\n", tot, 1);
	if (tot->map[play->y - 1][play->x] == 'C')
		g_collect++;
	if (tot->map[play->y - 1][play->x] == 'E')
		check_coll = check_avail_exit(tot, play);
	if (tot->map[play->y - 1][play->x] == '1' || check_coll == 0)
	{
		free(play);
		return ;
	}
	g_steps++;
	ft_printf("Number of steps: %u\n", g_steps);
	tot->map[play->y - 1][play->x] = 'P';
	tot->map[play->y][play->x] = '0';
	free(play);
	draw_map(tot);
	return ;
}

void	player_move_down(t_total *tot)
{
	t_point	*play;
	int		check_coll;

	check_coll = -1;
	play = find_player(tot);
	if (play->x == -1)
		err_screen("Unknown error: impossible to find player\n", tot, 1);
	if (tot->map[play->y + 1][play->x] == 'C')
		g_collect++;
	if (tot->map[play->y + 1][play->x] == 'E')
		check_coll = check_avail_exit(tot, play);
	if (tot->map[play->y + 1][play->x] == '1' || check_coll == 0)
	{
		free(play);
		return ;
	}
	g_steps++;
	ft_printf("Number of steps: %u\n", g_steps);
	tot->map[play->y + 1][play->x] = 'P';
	tot->map[play->y][play->x] = '0';
	free(play);
	draw_map(tot);
	return ;
}

void	player_move_left(t_total *tot)
{
	t_point	*play;
	int		check_coll;

	check_coll = -1;
	play = find_player(tot);
	if (play->x == -1)
		err_screen("Unknown error: impossible to find player\n", tot, 1);
	if (tot->map[play->y][play->x - 1] == 'C')
		g_collect++;
	if (tot->map[play->y][play->x - 1] == 'E')
		check_coll = check_avail_exit(tot, play);
	if (tot->map[play->y][play->x - 1] == '1' || check_coll == 0)
	{
		free(play);
		return ;
	}
	g_steps++;
	ft_printf("Number of steps: %u\n", g_steps);
	tot->map[play->y][play->x - 1] = 'P';
	tot->map[play->y][play->x] = '0';
	free(play);
	draw_map(tot);
	return ;
}

void	player_move_right(t_total *tot)
{
	t_point	*play;
	int		check_coll;

	check_coll = -1;
	play = find_player(tot);
	if (play->x == -1)
		err_screen("Unknown error: impossible to find player\n", tot, 1);
	if (tot->map[play->y][play->x + 1] == 'C')
		g_collect++;
	if (tot->map[play->y][play->x + 1] == 'E')
		check_coll = check_avail_exit(tot, play);
	if (tot->map[play->y][play->x + 1] == '1' || check_coll == 0)
	{
		free(play);
		return ;
	}
	g_steps++;
	ft_printf("Number of steps: %u\n", g_steps);
	tot->map[play->y][play->x + 1] = 'P';
	tot->map[play->y][play->x] = '0';
	free(play);
	draw_map(tot);
	return ;
}

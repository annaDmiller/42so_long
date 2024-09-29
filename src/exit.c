/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:29:39 by amelniko          #+#    #+#             */
/*   Updated: 2024/09/29 12:30:52 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_arr(char *mess, char **map)
{
	ft_free_arr(map);
	error(mess);
}

void	err_screen(char *mess, t_total *tot, int check)
{
	ft_free_arr(tot->map);
	free_map_img(tot->img, tot->mlx->mlx, check);
	mlx_destroy_window(tot->mlx->mlx, tot->mlx->win);
	mlx_destroy_display(tot->mlx->mlx);
	free(tot->mlx->mlx);
	error(mess);
}

void	succ_exit(char *mess, t_total *tot)
{
	ft_putstr_fd(mess, 1);
	ft_free_arr(tot->map);
	free_map_img(tot->img, tot->mlx->mlx, 1);
	mlx_destroy_window(tot->mlx->mlx, tot->mlx->win);
	mlx_destroy_display(tot->mlx->mlx);
	free(tot->mlx->mlx);
	exit(0);
}

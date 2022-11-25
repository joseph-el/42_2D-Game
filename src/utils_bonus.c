/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:49:25 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/22 22:30:08 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_path_b(t_grp *ap)
{
	write(1, "\033[32m[ so_long launch successfully ]\033[00m\n", 43);
	ap->data->t_key = ap->data->key;
	ap->c_pd = 1;
	ap->background = mlx_xpm_file_to_image(ap->mlx, "./assets/back2.xpm",
			&ap->i_size, &ap->i_size);
	ap->pd = mlx_xpm_file_to_image(ap->mlx, "./assets/player.xpm", &ap->i_size,
			&ap->i_size);
	ap->r_pd = mlx_xpm_file_to_image(ap->mlx, "./assets/right.xpm", &ap->i_size,
			&ap->i_size);
	ap->wall = mlx_xpm_file_to_image(ap->mlx, "./assets/wall.xpm", &ap->i_size,
			&ap->i_size);
	ap->key = mlx_xpm_file_to_image(ap->mlx, "./assets/coin1.xpm", &ap->i_size,
			&ap->i_size);
	ap->unlock = mlx_xpm_file_to_image(ap->mlx, "./assets/unlock.xpm",
			&ap->i_size, &ap->i_size);
	ap->lock = mlx_xpm_file_to_image(ap->mlx, "./assets/lock.xpm", &ap->i_size,
			&ap->i_size);
	ap->enemy = mlx_xpm_file_to_image(ap->mlx, "./assets/war0.xpm", &ap->i_size,
			&ap->i_size);
	ap->enemy1 = mlx_xpm_file_to_image(ap->mlx, "./assets/war1.xpm",
			&ap->i_size, &ap->i_size);
	ap->enemy2 = mlx_xpm_file_to_image(ap->mlx, "./assets/war2.xpm",
			&ap->i_size, &ap->i_size);
	ap->enemy3 = mlx_xpm_file_to_image(ap->mlx, "./assets/war3.xpm",
			&ap->i_size, &ap->i_size);
	ap->sc1 = mlx_xpm_file_to_image(ap->mlx, "./assets/score3.xpm", &ap->i_size,
			&ap->i_size);
	ap->sc2 = mlx_xpm_file_to_image(ap->mlx, "./assets/score2.xpm", &ap->i_size,
			&ap->i_size);
	ap->sc3 = mlx_xpm_file_to_image(ap->mlx, "./assets/score1.xpm", &ap->i_size,
			&ap->i_size);
	ap->sc4 = mlx_xpm_file_to_image(ap->mlx, "./assets/score4.xpm", &ap->i_size,
			&ap->i_size);
}

int	exit_program(t_grp *ap)
{
	mlx_destroy_window(ap->mlx, ap->window);
	clear_arr(ap->data->map);
	free(ap->data);
	free(ap);
	exit(0);
	return (0);
}

void	rip_program(t_grp *ap, bool check)
{
	if (check)
	{
		write(1, GREEN "\n\n\t|- - - BOYAAAH !! - - -|\n\n", 35);
		exit_program(ap);
	}
	write(1, RED "\n\n\t|- - - LOL! YOU DIE - - -|\n\n", 39);
	exit_program(ap);
}

void	free_memory(t_grp **ap)
{
	if ((*ap)->data->c_map)
		clear_arr((*ap)->data->c_map);
	if ((*ap)->data->map)
		clear_arr((*ap)->data->map);
	if ((*ap)->data->fd > 0)
		close((*ap)->data->fd);
	free((*ap)->data);
	free((*ap));
}

int	ft_close(t_grp *ap)
{
	exit_program(ap);
	return (0);
}

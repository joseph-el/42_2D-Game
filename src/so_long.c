/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:31:52 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/21 12:19:27 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_path_a(t_grp *ap)
{
	write(1, "\033[32m[ so_long launch successfully ]\033[00m\n", 43);
	ap->background = mlx_xpm_file_to_image(ap->mlx, "./assets/back1.xpm",
			&ap->i_size, &ap->i_size);
	ap->pd = mlx_xpm_file_to_image(ap->mlx, "./assets/player.xpm", &ap->i_size,
			&ap->i_size);
	ap->wall = mlx_xpm_file_to_image(ap->mlx, "./assets/wall.xpm", &ap->i_size,
			&ap->i_size);
	ap->key = mlx_xpm_file_to_image(ap->mlx, "./assets/coin1.xpm", &ap->i_size,
			&ap->i_size);
	ap->unlock = mlx_xpm_file_to_image(ap->mlx, "./assets/unlock.xpm",
			&ap->i_size, &ap->i_size);
	ap->lock = mlx_xpm_file_to_image(ap->mlx, "./assets/lock.xpm", &ap->i_size,
			&ap->i_size);
}

int	key_hook_a(int keycode, t_grp *ap)
{
	if (keycode == KEY_EXIT)
		exit_program(ap);
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S
		|| keycode == KEY_W)
		moving(keycode, ap);
	return (0);
}

void	moving(int key, t_grp *ap)
{
	bool		render;
	static int	move;

	render = 0;
	ap->data->id = ap->data->p_id + (key == KEY_S) - (key == KEY_W);
	ap->data->rw = ap->data->p_rw + (key == KEY_D) - (key == KEY_A);
	if (ft_strchr("C0", ap->data->map[ap->data->id][ap->data->rw]))
		render = 1;
	if (ap->data->map[ap->data->id][ap->data->rw] == 'C')
		ap->data->key--;
	if (ap->data->map[ap->data->id][ap->data->rw] == 'E' && ap->data->key == 0)
		rip_program(ap, 1);
	if (render)
	{
		ap->data->map[ap->data->p_id][ap->data->p_rw] = '0';
		ap->data->map[ap->data->id][ap->data->rw] = 'P';
		ap->data->p_id = ap->data->id;
		ap->data->p_rw = ap->data->rw;
		showing_img(ap);
		ft_putstr_fd("move : ", 1);
		ft_putnbr_fd(++move, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	showing_img(t_grp *ap)
{
	ap->data->id = 0;
	mlx_put_image_to_window(ap->mlx, ap->window, ap->background, 0, 0);
	while (ap->data->map[ap->data->id])
	{
		ap->data->rw = 0;
		while (ap->data->map[ap->data->id][ap->data->rw])
		{
			if (ap->data->map[ap->data->id][ap->data->rw] == '1')
				mlx_put_image_to_window(ap->mlx, ap->window, ap->wall,
					ap->data->rw * 65, ap->data->id * 65);
			if (ap->data->map[ap->data->id][ap->data->rw] == 'C')
				mlx_put_image_to_window(ap->mlx, ap->window, ap->key,
					ap->data->rw * 65, ap->data->id * 65);
			if (ap->data->map[ap->data->id][ap->data->rw] == 'P')
				mlx_put_image_to_window(ap->mlx, ap->window, ap->pd,
					ap->data->rw * 65, ap->data->id * 65);
			if (ap->data->map[ap->data->id][ap->data->rw] == 'E')
				mlx_put_image_to_window(ap->mlx, ap->window, ap->lock,
					ap->data->rw * 65, ap->data->id * 65);
			ap->data->rw++;
		}
		ap->data->id++;
	}
	return (SUCCESS);
}

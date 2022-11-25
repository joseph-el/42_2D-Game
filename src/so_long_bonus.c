/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:31:52 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/22 22:17:27 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook_b(int keycode, t_grp *ap)
{
	if (keycode == KEY_EXIT)
		exit_program(ap);
	if (keycode == KEY_A)
		ap->c_pd = 1;
	if (keycode == KEY_D)
		ap->c_pd = 0;
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S
		|| keycode == KEY_W)
		moving(keycode, ap);
	return (0);
}

void	level_score(t_grp *ap, int moved)
{
	char	*tmp;
	int		count;

	count = ap->data->t_key - ap->data->key;
	tmp = ft_itoa(moved);
	mlx_put_image_to_window(ap->mlx, ap->window, ap->wall, 30, 0);
	mlx_put_image_to_window(ap->mlx, ap->window, ap->wall, 100, 0);
	if (count == 0)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->sc1, 10, 35);
	else if (count == ap->data->t_key)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->sc4, 10, 35);
	else if (count <= ap->data->t_key / 2)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->sc2, 10, 35);
	else if (count >= ap->data->t_key / 2)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->sc3, 10, 35);
	mlx_string_put(ap->mlx, ap->window, 20, 10, 0x00FF0000, "move :");
	mlx_string_put(ap->mlx, ap->window, 120, 10, 0x00FF0000, tmp);
	free(tmp);
}

void	moving(int key, t_grp *ap)
{
	static int	move;
	bool		render;

	render = 0;
	ap->data->id = ap->data->p_id + (key == KEY_S) - (key == KEY_W);
	ap->data->rw = ap->data->p_rw + (key == KEY_D) - (key == KEY_A);
	if (ft_strchr("C0", ap->data->map[ap->data->id][ap->data->rw]))
		render = 1;
	if (ap->data->map[ap->data->id][ap->data->rw] == 'C')
		ap->data->key--;
	if (ap->data->map[ap->data->id][ap->data->rw] == 'E' && ap->data->key == 0)
		rip_program(ap, 1);
	if (ap->data->map[ap->data->id][ap->data->rw] == 'Z')
		rip_program(ap, 0);
	if (render)
	{
		ap->data->map[ap->data->p_id][ap->data->p_rw] = '0';
		ap->data->map[ap->data->id][ap->data->rw] = 'P';
		ap->data->p_id = ap->data->id;
		ap->data->p_rw = ap->data->rw;
		showing_img(ap);
		level_score(ap, ++move);
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
			if (ap->data->map[ap->data->id][ap->data->rw] == 'P' && !ap->c_pd)
				mlx_put_image_to_window(ap->mlx, ap->window, ap->pd, ap->data->rw * 65,
					ap->data->id * 65);
			if (ap->data->map[ap->data->id][ap->data->rw] == 'P' && ap->c_pd)
				mlx_put_image_to_window(ap->mlx, ap->window, ap->r_pd, ap->data->rw
					* 65, ap->data->id * 65);
			if (ap->data->map[ap->data->id][ap->data->rw] == 'E' && ap->data->key > 0)
				mlx_put_image_to_window(ap->mlx, ap->window, ap->lock, ap->data->rw
					* 65, ap->data->id * 65);
			if (ap->data->map[ap->data->id][ap->data->rw] == 'E' && ap->data->key == 0)
				mlx_put_image_to_window(ap->mlx, ap->window, ap->unlock, ap->data->rw
					* 65, ap->data->id * 65);
			ap->data->rw++;
		}
		ap->data->id++;
	}
	return (SUCCESS);
}

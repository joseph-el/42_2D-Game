/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:49:25 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/22 22:22:18 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

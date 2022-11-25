/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:29:22 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/22 22:28:49 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_grp	*ap;

	ap = NULL;
	if (ac == 1)
		return (signifies(0, NULL));
	ap = ft_calloc(1, sizeof(t_grp));
	if (!ap)
		return (EXIT_FAILURE);
	ap->data = ft_calloc(1, sizeof(t_data));
	if (!ap->data)
		return (EXIT_FAILURE);
	ap->data->vr = 0;
	if (!maps(av[1], ap->data))
	{
		free_memory(&ap);
		return (EXIT_FAILURE);
	}
	ap->mlx = mlx_init();
	ap->window = mlx_new_window(ap->mlx, 65 * ap->data->lenght, 65
		* ap->data->arr, "./so_long");
	get_path_a(ap);
	showing_img(ap);
	mlx_hook(ap->window, 2, 0, key_hook_a, ap);
	mlx_hook(ap->window, 17, 0, ft_close, ap);
	mlx_loop(ap->mlx);
	return (EXIT_SUCCESS);
}

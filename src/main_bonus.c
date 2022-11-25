/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:29:22 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/22 22:30:15 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_random_images(t_grp *ap, int x, int y)
{
	int	val;

	srand(time(NULL));
	val = rand();
	if (val % 2)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->enemy3, y * 65, x
			* 65);
	else if (val % 4)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->enemy2, y * 65, x
			* 65);
	else if (val % 6)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->enemy4, y * 65, x
			* 65);
	else if (val % 10)
		mlx_put_image_to_window(ap->mlx, ap->window, ap->enemy1, y * 65, x
			* 65);
	return (0);
}

int	fire_animation(t_grp *ap)
{
	int	id;
	int	rw;

	id = 0;
	while (ap->data->map[id])
	{
		rw = 0;
		while (ap->data->map[id][rw])
		{
			if (ap->data->map[id][rw] == 'Z')
				ft_random_images(ap, id, rw);
			rw++;
		}
		id++;
	}
	return (SUCCESS);
}

void	initialisation(t_grp *ap)
{
	ap->mlx = mlx_init();
	ap->window = mlx_new_window(ap->mlx, 65 * ap->data->lenght, 65
			* ap->data->arr, "./so_long");
	get_path_b(ap);
	mlx_put_image_to_window(ap->mlx, ap->window, ap->background, 0, 0);
	showing_img(ap);
}

int	main(int ac, char **av)
{
	t_grp	*ap;

	ap = NULL;
	if (ac == 1)
		return (signifies(0, ap->data));
	ap = ft_calloc(1, sizeof(t_grp));
	if (!ap)
		return (EXIT_FAILURE);
	ap->data = ft_calloc(1, sizeof(t_data));
	if (!ap->data)
		return (EXIT_FAILURE);
	ap->data->vr = 1;
	if (!maps(av[1], ap->data))
	{
		free_memory(&ap);
		return (EXIT_FAILURE);
	}
	initialisation(ap);
	mlx_hook(ap->window, 2, 0, key_hook_b, ap);
	mlx_loop_hook(ap->mlx, fire_animation, ap);
	mlx_hook(ap->window, 17, 0, ft_close, ap);
	mlx_loop(ap->mlx);
	return (EXIT_SUCCESS);
}

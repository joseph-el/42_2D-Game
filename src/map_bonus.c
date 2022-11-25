/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:47:45 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/21 12:16:15 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	fill_data_dup(t_data *ap, char target, int *id, int *rw)
{
	if (!ft_strchr("CPE01EZ", target) && ap->vr)
		return (FAILURE);
	if (!ft_strchr("CPE01E", target) && !ap->vr)
		return (FAILURE);
	if (target == 'C')
		ap->key++;
	if (target == 'P')
	{
		if (ap->pd == 1)
			return (FAILURE);
		ap->pd = 1;
		ap->p_id = *id;
		ap->p_rw = *rw;
	}
	if (target == 'E')
	{
		if (ap->p_exit == 1)
			return (FAILURE);
		ap->p_exit = 1;
	}
	return (SUCCESS);
}

void	path(char **line, int id, int rw, t_data *ap)
{
	if (line[id][rw] == 'C')
		ap->t_p++;
	if (id < 0 || id >= ap->arr || rw < 0 || rw >= ap->lenght
		|| ft_strchr("1EZ", line[id][rw]))
		return ;
	line[id][rw] = '1';
	path(line, id - 1, rw, ap);
	path(line, id + 1, rw, ap);
	path(line, id, rw - 1, ap);
	path(line, id, rw + 1, ap);
}

int	detecting(t_data *ap)
{
	int	id;
	int	rw;

	ap->lenght = ft_strlen(ap->map[0]);
	if (!search(ap->map[0], '1', ap->lenght) || !search(ap->map[ap->arr - 1],
			'1', ap->lenght))
		return (FAILURE);
	id = 1;
	while (ap->map[id])
	{
		rw = 0;
		while (ap->map[id][rw])
		{
			if ((int)ft_strlen(ap->map[id]) != ap->lenght)
				return (signifies(1, ap));
			if (ap->map[id][0] != '1' || ap->map[id][ap->lenght - 1] != '1')
				return (signifies(1, ap));
			if (!fill_data_dup(ap, ap->map[id][rw], &id, &rw))
				return (signifies(1, ap));
			rw++;
		}
		id++;
	}
	return (SUCCESS);
}

int	maps(char *args, t_data *ap)
{
	if (!ft_strchr(args, '.'))
		return (signifies(2, ap));
	if (ft_strcmp(ft_strrchr(args, '.'), ".ber") != 0)
		return (signifies(2, ap));
	ap->fd = open(args, O_RDONLY);
	if (ap->fd == -1)
		return (signifies(3, ap));
	add_matrix(ap);
	if (!ap->map || !ap->c_map)
		return (FAILURE);
	if (!detecting(ap))
		return (FAILURE);
	path(ap->c_map, ap->p_id, ap->p_rw, ap);
	if ((ap->p_exit + ap->key) != (ap->t_p + ap->p_exit))
		return (signifies(1, ap));
	if (ap->p_exit == 0 || ap->pd == 0 || ap->key == 0)
		return (signifies(1, ap));
	clear_arr(ap->c_map);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:40:17 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/21 12:44:43 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	signifies(int gnl, t_data *ap)
{
	write(2, "ERROR :\n", 9);
	if (gnl == 0)
		write(2, RED "INVALID ARGUMENNT TRY ./so_long <PATH> '\n", 49);
	if (gnl == 1)
		write(2, RED "SOMETHING ELSE IN MAP \n", 30);
	if (gnl == 2)
		write(2, RED "INVALIDE SIGNIFIES TRY '.ber' IN END OF YOUR FILE NAME\n",
			62);
	if (gnl == 3)
	{
		write(2, RED "FILE NOT FOUND TRY 'map.ber'\n", 36);
		close(ap->fd);
	}
	return (FAILURE);
}

int	add_matrix(t_data *ap)
{
	char	*line;
	char	*tmp;

	line = NULL;
	while (1)
	{
		tmp = get_next_line(ap->fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		if (tmp[0] == '\n')
			return (signifies(2, ap));
		line = ft_strjoin(line, tmp);
		ap->arr++;
		free(tmp);
	}
	if (!line)
		return (signifies(1, ap));
	ap->map = ft_split(line, '\n');
	ap->c_map = ft_split(line, '\n');
	free(line);
	return (SUCCESS);
}

void	clear_arr(char **error)
{
	int	i;

	i = 0;
	while (error[i])
		free(error[i++]);
	free(error);
}

int	search(char *str, int targeet, unsigned int len)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == targeet)
		i++;
	if ((int)len == i)
		return (SUCCESS);
	return (FAILURE);
}

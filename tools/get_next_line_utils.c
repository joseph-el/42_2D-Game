/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:41:15 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/18 01:27:47 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*found(char *str)
{
	if (!str)
		return (0);
	while (*str && *(str) != '\n')
		str++;
	if (*str == '\0' && *(str) != '\n')
		return (NULL);
	return (str);
}

char	*ft_subline(char *stash)
{
	char	*line;
	int		len;
	int		i;

	if (!*stash)
		return (NULL);
	len = (ft_strlen(stash) - ft_strlen(found(stash)) + 1);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i] && i < len)
		line[i] = stash[i];
	line[i] = 0;
	return (line);
}

char	*cleaning_stash(char *stash)
{
	char	*str;
	char	*ptr;
	int		i;

	if (!found(stash))
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	ptr = str;
	if (stash[i] && stash[i] == '\n')
		i++;
	while (stash[i])
		*str++ = stash[i++];
	*str = 0;
	free(stash);
	return (ptr);
}

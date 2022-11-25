/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:22:00 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/13 21:09:39 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	char	*ptr;
	int		len;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer)) + 1);
	if (!str)
		return (NULL);
	ptr = str;
	len = 0;
	while (stash[len])
		*str++ = stash[len++];
	while (*buffer)
		*str++ = *buffer++;
	*str = 0;
	free(stash);
	return (ptr);
}

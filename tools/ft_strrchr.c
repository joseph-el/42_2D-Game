/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:22:40 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/18 01:31:26 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	str += len;
	while (i <= len)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
		i ++;
	}
	return (NULL);
}

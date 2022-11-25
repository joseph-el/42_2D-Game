/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:20:44 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/20 13:53:33 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	count_len(int nb)
{
	long	n;
	int		url;

	n = nb;
	url = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		url++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		url++;
	}
	return (url);
}

char	*set_zero(char *str)
{
	str[0] = '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = count_len(nb);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		return (set_zero(str));
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		str[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
	return (str);
}

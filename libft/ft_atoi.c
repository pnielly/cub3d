/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:24:52 by pnielly           #+#    #+#             */
/*   Updated: 2019/10/21 12:08:49 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == '\f' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\r' || str[i] == '\v' ||
				str[i] == ' ') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = ft_sign(str[i]);
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

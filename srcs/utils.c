/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:31:36 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/24 15:36:04 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

int		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (1);
}

double	ft_min(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

double	ft_max(double a, double b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

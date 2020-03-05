/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:31:36 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/04 11:11:46 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

int		ft_putstr(char *str)
{
	int	i;

	i = 0;
	write(1, "Error\n", 6);
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

void	ft_check_error(t_stock *stock, char **tab)
{
	if (stock->start_read_map && tab[0] && !ft_strchr("01234NSEW", *tab[0]))
		stock->error = 1;
	if (stock->end_read_map && tab[0])
		stock->error = 1;
}

int		ft_walled(t_stock *stock, int j)
{
	char	*s;
	int		i;

	i = 0;
	if (ft_strlen(stock->map->tab[j]) > ft_strlen(stock->map->tab[j - 1]))
		s = stock->map->tab[j];
	else
		s = stock->map->tab[j - 1];
	i = (int)ft_strlen(s) - stock->map->diff;
	while (s[i])
	{
		if (s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

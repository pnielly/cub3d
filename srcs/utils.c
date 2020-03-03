/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:31:36 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 14:08:39 by pnielly          ###   ########.fr       */
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
//	printf("error = %d et tab = %c\n", stock->error, tab[0][0]);
	if (stock->start_read_map && tab[0] && !ft_strchr("01234NSEW", *tab[0]))
		stock->error = 1;
	printf("tab[0] = %s et error = %d\n", tab[0], stock->error);
	if (stock->end_read_map && tab[0])
		stock->error = 1;
//	printf("error1 = %d et tab = %c\n", stock->error, tab[0][0]);
}

int		ft_walled(t_stock *stock, int j)
{
	char	*s;
	int	i;

	i = 0;
	if (ft_strlen(stock->map->tab[j]) > ft_strlen(stock->map->tab[j - 1]))
		s = stock->map->tab[j];
	else
		s = stock->map->tab[j - 1];
	i = (int)ft_strlen(s) - stock->map->diff;
	printf("s = %s, s[i] = <%c>, i = %d\n", s, s[i], i);
	printf("diff = %d\n", stock->map->diff);
	printf("tab[%d] = %s len = %d\ntab[%d] = %s len = %d\n", j - 1, stock->map->tab[j - 1], (int)ft_strlen(stock->map->tab[j - 1]), j, stock->map->tab[j], (int)ft_strlen(stock->map->tab[j]));
	while (s[i])
	{
		if (s[i] != '1')
		{
			printf("s[i] = <%c>, i = %d\n", s[i], i);
			return (1);
		}
		i++;
	}
	return (0);
}

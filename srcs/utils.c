/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:31:36 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/06 13:14:11 by pnielly          ###   ########.fr       */
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

char	*ft_reverse_line(char *s)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(s);
	i = 0;
	while (i < (int)(len / 2))
	{
		tmp = s[len - 1 - i];
		s[len - 1 - i] = s[i];
		s[i] = tmp;
		i++;
	}
	return (s);
}

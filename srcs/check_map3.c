/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:37:06 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 13:48:31 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_resolution(t_stock *stock, char **tab)
{
	if (!stock->r)
	{
		if (!(stock->r = malloc(sizeof(t_size))))
			return (ft_putstr("MALLOC FAILED\n"));
	}
	if (!tab[1])
		return (ft_putstr("MISSING DATA IN RESOLUTION\n"));
	else if (tab[0][1])
	{
		stock->r->x = ft_atoi(tab[0] + 1);
		stock->r->y = ft_atoi(tab[1]);
	}
	else if (tab[2])
	{
		stock->r->x = ft_atoi(tab[1]);
		stock->r->y = ft_atoi(tab[2]);
	}
	else
		stock->error = 1;
	return (0);
}

char	*ft_path(char **tab, char *zone)
{
	int	i;

	i = ft_strlen(zone);
	if (tab[0][i])
	{
		return (ft_strdup(tab[0] + i));
	}
	else if (tab[1])
		return (ft_strdup(tab[1]));
	else
		return (NULL);
}

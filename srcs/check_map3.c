/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:37:06 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 16:51:51 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_resolution(t_stock *stock, char **tab)
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

int		ft_assign_ceiling(t_stock *stock, char *line)
{
	if (!stock->c)
	{
		if (!(stock->c = malloc(sizeof(t_color))))
		{
			stock->error = 1;
			return (ft_putstr("MALLOC FAILED\n"));
		}
	}
	line++;
	stock->c->r = ft_atoi(line);
	while (line[0] != ',')
		line++;
	line++;
	stock->c->g = ft_atoi(line);
	while (line[0] != ',')
		line++;
	line++;
	stock->c->b = ft_atoi(line);
	return (0);
}

int		ft_assign_floor(t_stock *stock, char *line)
{
	if (!stock->f)
	{
		if (!(stock->f = malloc(sizeof(t_color))))
		{
			stock->error = 1;
			return (ft_putstr("MALLOC FAILED\n"));
		}
	}
	line++;
	stock->f->r = ft_atoi(line);
	while (line[0] != ',')
		line++;
	line++;
	stock->f->g = ft_atoi(line);
	while (line[0] != ',')
		line++;
	line++;
	stock->f->b = ft_atoi(line);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:52:43 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 16:03:07 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_assign_ceiling(char *line, t_stock *stock, char **tab)
{
	int	i;

	if (!(ft_strncmp(line, "C ", 2)))
	{
		i = 0;
		if (!(stock->c = malloc(sizeof(t_color))))
			return (ft_putstr("MALLOC FAILED\n"));
		stock->c->r = ft_atoi(tab[1]);
		while (tab[1][i] != ',')
			i++;
		i++;
		stock->c->g = ft_atoi(tab[1] + i);
		while (tab[1][i] != ',')
			i++;
		i++;
		stock->c->b = ft_atoi(tab[1] + i);
	}
	return (0);
}

int	ft_assign_floor(char *line, t_stock *stock, char **tab)
{
	int	i;

	if (!(ft_strncmp(line, "F ", 2)))
	{
		i = 0;
		if (!(stock->f = malloc(sizeof(t_color))))
			return (ft_putstr("MALLOC FAILED\n"));
		stock->f->r = ft_atoi(tab[1]);
		while (tab[1][i] != ',')
			i++;
		i++;
		stock->f->g = ft_atoi(tab[1] + i);
		while (tab[1][i] != ',')
			i++;
		i++;
		stock->f->b = ft_atoi(tab[1] + i);
	}
	return (0);
}

int	ft_assign(char *line, t_stock *stock, char **tab)
{
	if (line[0] == 'R')
	{
		if (!(stock->r = malloc(sizeof(t_size))))
			return (ft_putstr("MALLOC FAILED\n"));
		stock->r->x = ft_atoi(tab[1]);
		stock->r->y = ft_atoi(tab[2]);
	}
	if (!(ft_strncmp(line, "NO", 2)))
		stock->no = ft_strdup(tab[1]);
	if (!(ft_strncmp(line, "SO", 2)))
		stock->so = ft_strdup(tab[1]);
	if (!(ft_strncmp(line, "WE", 2)))
		stock->we = ft_strdup(tab[1]);
	if (!(ft_strncmp(line, "EA", 2)))
		stock->ea = ft_strdup(tab[1]);
	if (!(ft_strncmp(line, "S ", 2)))
		stock->s = ft_strdup(tab[1]);
	if (ft_assign_floor(line, stock, tab))
		return (ft_putstr("COLOR ASSIGNMENT FAILED\n"));
	if (ft_assign_ceiling(line, stock, tab))
		return (ft_putstr("COLOR ASSIGNMENT FAILED\n"));
	return (0);
}

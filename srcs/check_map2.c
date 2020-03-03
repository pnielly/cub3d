/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:52:43 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 14:26:50 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checked(char **tab, t_stock *stock)
{
	int	i;

	if (tab[0][0] == 'R')
		stock->checked[0]++;
	else if (!(ft_strncmp(tab[0], "NO", 2)))
		stock->checked[1]++;
	else if (!(ft_strncmp(tab[0], "SO", 2)))
		stock->checked[2]++;
	else if (!(ft_strncmp(tab[0], "WE", 2)))
		stock->checked[3]++;
	else if (!(ft_strncmp(tab[0], "EA", 2)))
		stock->checked[4]++;
	else if (!(ft_strncmp(tab[0], "S", 1)))
		stock->checked[5]++;
	else if (!(ft_strncmp(tab[0], "F", 1)))
		stock->checked[6]++;
	else if (!(ft_strncmp(tab[0], "C", 1)))
		stock->checked[7]++;
	i = -1;
	while (++i <= 7)
	{
		if (!ft_strchr("01", stock->checked[i]))
			stock->error = 1;
	}
}

int	ft_assign_ceiling(t_stock *stock, char *line)
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

int	ft_assign_floor(t_stock *stock, char *line)
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

int	ft_assign(t_stock *stock, char **tab, char *line)
{
	printf("line = %s et start_read_map = %d et end = %d\n", tab[0], stock->start_read_map, stock->end_read_map);
	if (!tab[0])
	{
		if (stock->start_read_map)	
			stock->end_read_map = 1;
	}
	else if (tab[0][0] == 'R')
	{
		if (ft_resolution(stock, tab))
			return (ft_putstr("ASSIGNMENT FAILED\n"));
	}
	else if (!(ft_strncmp(tab[0], "NO", 2)))
		stock->no = ft_path(tab, "NO");
	else if (!(ft_strncmp(tab[0], "SO", 2)))
		stock->so = ft_path(tab, "SO");
	else if (!(ft_strncmp(tab[0], "WE", 2)))
		stock->we = ft_path(tab, "WE");
	else if (!(ft_strncmp(tab[0], "EA", 2)))
		stock->ea = ft_path(tab, "EA");
	else if (!(ft_strncmp(tab[0], "S", 1)))
		stock->s = ft_path(tab, "S");
	else if (!(ft_strncmp(tab[0], "F", 1)))
		ft_assign_floor(stock, line);
	else if (!(ft_strncmp(tab[0], "C", 1)))
		ft_assign_ceiling(stock, line);
	else if ((!ft_strchr("01234NSEW", *tab[0])) && stock->start_read_map)
		stock->end_read_map = 1;
	else if (ft_strchr("01234NSEW", *tab[0]))
		stock->start_read_map = 1;
	else
		stock->error = 1;
	if (tab[0])
		ft_checked(tab, stock);
	return (0);
}

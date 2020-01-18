/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:10:08 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 16:50:26 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_read_map(t_stock *stock, int fd)
{
	char	**tab;
	t_list	*tmp;
	char	*line;
	int	j;

	if (!(stock->map = malloc(sizeof(t_map))))
		return (ft_putstr("MALLOC FAILED\n"));
	while (get_next_line(fd, &line) > 0 && !ft_isdigit(line[0]))
	{
		if (!(tab = ft_split(line, ' ')))
			return (ft_putstr("MALLOC FAILED\n"));
		/** resolution **/
		if (line[0] == 'R')
		{
			if (!(stock->R = malloc(sizeof(t_size))))
				return (ft_putstr("MALLOC FAILED\n"));
			stock->R->x = ft_atoi(tab[1]);
			stock->R->y = ft_atoi(tab[2]);
		}
		/** textures **/
		if (!(ft_strncmp(line, "NO", 2)))
			stock->NO = tab[1];
		if (!(ft_strncmp(line, "SO", 2)))
			stock->SO = tab[1];
		if (!(ft_strncmp(line, "WE", 2)))
			stock->WE = tab[1];
		if (!(ft_strncmp(line, "EA", 2)))
			stock->EA = tab[1];
		/** sprite (object on the map) **/
		if (!(ft_strncmp(line, "S ", 2)))
			stock->S = tab[1];
		/** color floor **/
		if (!(ft_strncmp(line, "F ", 2)))
		{
			if (!(stock->F = malloc(sizeof(t_color))))
				return (ft_putstr("MALLOC FAILED\n"));
			stock->F->R = ft_atoi(tab[1]);
			while (*tab[1] != ',')
				tab[1]++;
			stock->F->G = ft_atoi(tab[1]);
			while (*tab[1] != ',')
				tab[1]++;
			stock->F->B = ft_atoi(tab[1]);
			if (stock->F->R < 255 && stock->F->R >= 0 && stock->F->G < 255 && stock->F->G >= 0 && stock->F->B < 255 && stock->F->B >= 0)
				stock->F->check = 1;
		}
		/** color ceiling **/
		if (!(ft_strncmp(line, "C ", 2)))
		{
			if (!(stock->C = malloc(sizeof(t_color))))
				return (ft_putstr("MALLOC FAILED\n"));
			stock->C->R = ft_atoi(tab[1]);
			while (*tab[1] != ',')
				tab[1]++;
			stock->C->G = ft_atoi(tab[1]);
			while (*tab[1] != ',')
				tab[1]++;
			stock->C->B = ft_atoi(tab[1]);
			if (stock->C->R < 255 && stock->C->R >= 0 && stock->C->G < 255 && stock->C->G >= 0 && stock->C->B < 255 && stock->C->B >= 0)
				stock->C->check = 1;
		}
		free(tab);
		free(line);
		}
	/** map **/
	/** first line of the map --> stored in struct **/
	if (line && line[0])
	{
		printf("line = %s\n", line);
		if (!(stock->map->packing = malloc(sizeof(t_list*))))
			return (ft_putstr("MALLOC FAILED\n"));
		stock->map->packing->content = ft_strdup(line);
		stock->map->packing->next = 0;
		stock->map->nb_lines = 1;
	}
	/** next lines of the map --> stored in struct**/
	while (get_next_line(fd, &line) > 0 && ft_isdigit(line[0]))
	{
		printf("line = %s\n", line);
		if (!(tmp = malloc(sizeof(t_list))))
			return (ft_putstr("MALLOC FAILED\n"));
		tmp->content = ft_strdup(line);
		tmp->next = 0;
		ft_lstadd_back(&stock->map->packing, tmp);
		stock->map->nb_lines++;
	}
	/** put struct into array **/
	j = 0;
	tmp = stock->map->packing;
	/** size_line **/
	stock->map->size_line = ft_strlen(ft_strxclude(tmp->content, " "));
	/** put struct into array (suite) **/
	if (!(stock->map->tab = malloc(sizeof(char) * stock->map->size_line * stock->map->nb_lines + 1)))
		return (ft_putstr("MALLOC FAILED\n"));
	while (j < stock->map->nb_lines)
	{
		stock->map->tab[j] = ft_strxclude(tmp->content, " ");
		/** check map's shape **/
		if ((int)ft_strlen(stock->map->tab[j]) != stock->map->size_line)
			return (ft_putstr("THE MAP IS NOT A RECTANGLE\n"));
		tmp = tmp->next;
		j++;
	}
	/** check if we got all the needed data **/
	if (!stock->R->x || !stock->R->y || !stock->NO || !stock->SO || !stock->WE || !stock->EA || !stock->S || !stock->F->check || !stock->C->check)
		return (ft_putstr("MISSING DATA ABOVE MAP\n"));
	return (0);
}

int	ft_check_map(t_stock *stock, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (ft_read_map(stock, fd))
		return (ft_putstr("ERROR READING MAP\n"));
	if (close(fd) == -1)
		return (ft_putstr("CLOSE() MAP_FILE FAILED\n"));;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:10:08 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 20:30:12 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_build_map_tab(t_list *alst, t_stock *stock)
{
	t_list	*tmp;
	int		j;

	tmp = alst;
	j = -1;
	while (++j < stock->map->nb_lines)
	{
		stock->map->tab[j] = ft_strdup(tmp->content);
		if ((int)ft_strlen(stock->map->tab[j]) != stock->map->size_line)
			return (ft_putstr("THE MAP IS NOT A RECTANGLE\n"));
		tmp = tmp->next;
	}
	if (!stock->r->x || !stock->r->y || !stock->no || !stock->so
					|| !stock->we || !stock->ea || !stock->s)
		return (ft_putstr("MISSING DATA ABOVE MAP OR WRONG DATA ORDER\n"));
	return (0);
}

t_list	*ft_line_map(char *line, t_stock *stock)
{
	t_list	*tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = ft_strxclude(line, " ");
	tmp->next = 0;
	stock->map->size_line = ft_strlen(tmp->content);
	stock->map->nb_lines++;
	return (tmp);
}

int		ft_read_file(t_stock *stock, int fd)
{
	char	**tab;
	t_list	*tmp;
	char	*line;

	if (!(stock->map = malloc(sizeof(t_map))))
		return (ft_putstr("MALLOC FAILED\n"));
	stock->map->nb_lines = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tab = ft_split(line, ' ')))
			return (ft_putstr("MALLOC FAILED\n"));
		if (ft_assign(line, stock, tab))
			return (ft_putstr("ASSIGN FAILED\n"));
		if (ft_isdigit(line[0]))
		{
			tmp = ft_line_map(line, stock);
			ft_lstadd_back(&stock->list, tmp);
		}
		ft_free_tab(tab);
		free(line);
	}
	free(line);
	stock->po = "./textures/walls/wood.xpm";
	stock->texlife = "./textures/walls/wood.xpm";
	return (0);
}

int		ft_check_map(t_stock *stock, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (ft_read_file(stock, fd))
		return (ft_putstr("ERROR READING MAP\n"));
	if (close(fd) == -1)
		return (ft_putstr("CLOSE() MAP_FILE FAILED\n"));
	if (!(stock->map->tab = malloc(sizeof(char)
			* (stock->map->size_line * stock->map->nb_lines + 1))))
		return (ft_putstr("MALLOC FAILED\n"));
	if (ft_build_map_tab(stock->list, stock))
		return (ft_putstr("BUILD MAP FAILED\n"));
	ft_lstclear(&stock->list, free);
	return (0);
}

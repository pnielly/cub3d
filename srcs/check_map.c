/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:10:08 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/05 15:10:49 by pnielly          ###   ########.fr       */
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
		tmp = tmp->next;
	}
	if (!stock->r->x || !stock->r->y || !stock->no || !stock->so
					|| !stock->we || !stock->ea || !stock->s)
		return (ft_putstr("MISSING DATA ABOVE MAP OR WRONG DATA ORDER\n"));
	return (0);
}

char	*ft_3_spaces_1_zero(char *line)
{
	int		i;

	if (line[0] == ' ' && line[1] == ' ')
		line[0] = '0';
	i = 1;
	while (line[i + 1])
	{
		if (line[i - 1] == ' ' && line[i] == ' ' && line[i + 1] == ' ')
			line[i] = '0';
		i++;
	}
	return (line);
}

t_list	*ft_line_map(char *line, t_stock *stock)
{
	t_list	*tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = ft_strxclude(ft_3_spaces_1_zero(line), " ");
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
		if (ft_assign(stock, tab, line))
			return (ft_putstr("ASSIGN FAILED\n"));
		if (ft_isdigit(line[0]))
		{
			stock->start_read_map = 1;
			tmp = ft_line_map(line, stock);
			ft_lstadd_back(&stock->list, tmp);
		}
		if (tab[0])
			ft_check_error(stock, tab);
		ft_free_tab(tab);
		free(line);
	}
	return (0);
}

int		ft_check_map(t_stock *stock, char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_putstr("MAP FILE DOES NOT EXIST !\n"));
	stock->checked = ft_strdup("\060\060\060\060\060\060\060\060");
	if (ft_read_file(stock, fd))
		return (ft_putstr("ERROR READING MAP\n"));
	if (ft_strncmp(stock->checked, "11111111", 8))
		return (ft_putstr("MISSING OR DUPLICATED DATA\n"));
	ft_free_other(stock->checked);
	stock->po = "./textures/walls/wood.xpm";
	if (close(fd) == -1)
		return (ft_putstr("CLOSE() MAP_FILE FAILED\n"));
	if (!(stock->map->tab = malloc(sizeof(char)
			* (stock->map->size_line * stock->map->nb_lines + 1))))
		return (ft_putstr("MALLOC FAILED\n"));
	if (ft_build_map_tab(stock->list, stock))
		return (ft_putstr("BUILD MAP FAILED\n"));
	if (stock->error == 1)
		return (ft_putstr("PROBLEM IN THE MAP FILE\n"));
	ft_lstclear(&stock->list, free);
	return (0);
}
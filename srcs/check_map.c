/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:10:08 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/11 10:38:41 by pnielly          ###   ########.fr       */
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
		stock->map->tab[j] = ft_reverse_line(ft_fill_line(tmp->content,
					' ', stock->map->size_line));
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
	tmp->content = ft_strdup(line);
	tmp->next = 0;
	stock->map->size_line = ft_max(ft_strlen(tmp->content),
			stock->map->size_line);
	stock->map->nb_lines++;
	return (tmp);
}

int		ft_read_file(t_stock *stock, int fd)
{
	char	**tab;
	t_list	*tmp;
	char	*line;

	stock->map->nb_lines = 0;
	stock->map->size_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_split(line, ' ');
		if (ft_assign(stock, tab, line))
			return (ft_putstr("ASSIGN FAILED\n"));
		if (ft_isdigit(ft_first_char(line)))
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
	free(line);
	return (0);
}

int		ft_check_map(t_stock *stock, char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_putstr("MAP FILE DOES NOT EXIST !\n"));
	stock->checked = ft_strdup("\060\060\060\060\060\060\060\060");
	if (!(stock->map = malloc(sizeof(t_map))))
		return (ft_putstr("MALLOC FAILED\n"));
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

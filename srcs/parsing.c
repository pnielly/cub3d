/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:16:47 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/06 13:50:16 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dir2(t_stock *stock, char c)
{
	if (c == 'E')
	{
		stock->player->dir->x = -1;
		stock->player->dir->y = 0;
		stock->plane_ory = 0.88;
		stock->plane_orx = 0;
	}
	else if (c == 'W')
	{
		stock->player->dir->x = 1;
		stock->player->dir->y = 0;
		stock->plane_ory = 0.88;
		stock->plane_orx = 0;
	}
}

int		ft_dir(t_stock *stock, char c)
{
	if (!(stock->player->dir = malloc(sizeof(t_size))))
		return (ft_putstr("MALLOC FAILED - PLAYER DIR"));
	if (c == 'N')
	{
		stock->player->dir->x = 0;
		stock->player->dir->y = -1;
		stock->plane_ory = 0;
		stock->plane_orx = 0.88;
	}
	else if (c == 'S')
	{
		stock->player->dir->x = 0;
		stock->player->dir->y = 1;
		stock->plane_ory = 0;
		stock->plane_orx = 0.88;
	}
	else
		ft_dir2(stock, c);
	return (0);
}

/*
** IN FT_ASSIGN :
** 1. checking walls around map
** 2. checking for unauthorized char in map
** 3. checking for duplicate players
** 4. player initial position and orientation
** --> plane = camera orientation (initial orientation
** 	determines <sign> and <value> of dir.x and dir.y)
** 5. number of objects (their position will be parsed in the "sprite" file)
*/

int		ft_check_n_assign(int i, int j, t_stock *stock)
{
	if (ft_check_color_fc(stock))
		return (ft_putstr("WRONG COLOR : SHOULD BELONG TO [0;255]\n"));
	if (ft_border(stock, i, j))
		return (ft_putstr("MAP ISN'T SURROUNDED BY WALLS\n"));
	if (stock->map->tab[j][i] && !ft_strchr("01234NSEW ",
				stock->map->tab[j][i]))
		return (ft_putstr("UNDEFINED CHARACTERS IN THE MAP\n"));
	if (stock->player->start_pos == 1
		&& ft_strchr("NSEW", stock->map->tab[j][i]))
		return (ft_putstr("MORE THAN ONE PLAYER STARTING POINT\n"));
	if (!stock->player->start_pos && ft_strchr("NSEW", stock->map->tab[j][i]))
	{
		stock->player->start_pos = 1;
		ft_dir(stock, stock->map->tab[j][i]);
		stock->plane_x = stock->player->dir->y * stock->plane_orx;
		stock->plane_y = -stock->player->dir->x * stock->plane_ory;
		stock->player->pos_x = i + 0.5;
		stock->player->pos_y = j + 0.5;
		stock->map->tab[j][i] = '0';
	}
	if (stock->map->tab[j][i] == '2')
		stock->nb_sprites++;
	return (0);
}

int		ft_parsing(t_stock *stock)
{
	int	i;
	int	j;

	j = 0;
	stock->player->start_pos = 0;
	stock->map->nb_lines--;
	stock->map->size_line--;
	while (j <= stock->map->nb_lines)
	{
		i = 0;
		while (i <= stock->map->size_line)
		{
			if (j)
				stock->map->diff = abs((int)(ft_strlen(stock->map->tab[j - 1])
							- ft_strlen(stock->map->tab[j])));
			if (ft_check_n_assign(i, j, stock))
				return (1);
			i++;
		}
		j++;
	}
	if (!stock->player->start_pos)
		return (ft_putstr("PLAYER MISSING\n"));
	return (0);
}

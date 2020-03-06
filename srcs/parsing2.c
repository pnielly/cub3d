/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:25:57 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/06 13:00:41 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_border(t_stock *stock, int i, int j)
{
	if (i * j == 0 || i == (int)ft_strlen(stock->map->tab[j]) - 1
			|| j == stock->map->nb_lines)
	{
		if (!ft_strchr("1 ", stock->map->tab[j][i]))
			return (1);
	}
	if (j * i != 0 && i != (int)ft_strlen(stock->map->tab[j]) - 1
			&& j != stock->map->nb_lines
			&& !ft_strchr("13 ", stock->map->tab[j][i]))
	{
		if (ft_strchr(" ", stock->map->tab[j][i - 1])
				|| ft_strchr(" ", stock->map->tab[j][i + 1])
				|| ft_strchr(" ", stock->map->tab[j - 1][i])
				|| ft_strchr(" ", stock->map->tab[j + 1][i]))
			return (1);
	}
	return (0);
}

int	ft_check_color_fc(t_stock *stock)
{
	if (stock->f->r < 0 || stock->f->r > 255)
		return (1);
	if (stock->f->g < 0 || stock->f->g > 255)
		return (1);
	if (stock->f->b < 0 || stock->f->b > 255)
		return (1);
	if (stock->c->r < 0 || stock->c->r > 255)
		return (1);
	if (stock->c->g < 0 || stock->c->g > 255)
		return (1);
	if (stock->c->b < 0 || stock->c->b > 255)
		return (1);
	return (0);
}

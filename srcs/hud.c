/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:33:36 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/06 13:40:38 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_hud(t_stock *stock)
{
	int		life;
	int		width;

	width = stock->r->y / 25;
	stock->hud = 1;
	life = stock->life + 1;
	stock->tex_y = stock->r->y / 20;
	while (life-- > 1)
	{
		while (stock->tex_y-- + width > stock->r->y / 20)
		{
			stock->tex_x = life * stock->r->x / 3;
			while (stock->tex_x-- > 0)
			{
				ft_put_pixel(stock, stock->tex_x, stock->tex_y, RED);
			}
		}
	}
	stock->hud = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:33:36 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 21:06:20 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_hud2(t_stock *stock, int life, int x, int y)
{
	while (life)
	{
		y = 10;
		stock->tex_y = 64;
		while (stock->tex_y-- > 0)
		{
			x = (life - 1) * 64 + 2;
			stock->tex_x = 64;
			while (stock->tex_x-- > 0)
			{
				if (ft_tex_color(stock->tex_life, stock->tex_x,
							64 - stock->tex_y) != PINK)
					ft_put_pixel(stock, x++, y,
							ft_tex_color(stock->tex_life,
								stock->tex_x, 64 - stock->tex_y));
			}
			y++;
		}
		life--;
	}
	stock->hud = 0;
	return (0);
}

int			ft_hud(t_stock *stock)
{
	int		life;
	int		x;
	int		y;

	stock->hud = 1;
	life = stock->life;
	x = 0;
	y = 0;
	return (ft_hud2(stock, life, x, y));
}

/*
** ft_init_hud is called in game.c
*/

int			ft_init_hud(t_stock *stock)
{
	if (!(stock->tex_life = ft_new_tex(stock, stock->texlife)))
		return (ft_putstr("MALLOC FAILED (TEX LIFE)\n"));
	return (0);
}

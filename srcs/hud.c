/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:33:36 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 15:21:15 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_hud(t_stock *stock)
{
	int	life;
	char	*texlife_path;
	int	x;
	int	y;

	stock->hud = 1;
	life = stock->life;
	texlife_path = "./textures/walls/wood.xpm";
	if (!(stock->texlife = ft_new_tex(stock, texlife_path)))
				return (ft_putstr("MAlLOC FAILED (TEX LIFE)\n"));
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
				if (ft_tex_color(stock->texlife, stock->tex_x, 64 - stock->tex_y) != PINK)
					ft_put_pixel(stock, x++, y, ft_tex_color(stock->texlife, stock->tex_x, 64 - stock->tex_y));
			}
			y++;
		}
		life--;
	}
	stock->hud = 0;
	return (0);
}

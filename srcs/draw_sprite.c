/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:40:23 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 17:16:57 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** FT_DISPLAY : draw every object pixel that is in the FOV
*/

void	ft_display_sprite(t_stock *stock, double transform_y,
			int sprite_screen_x)
{
	int				l;
	int				c;
	unsigned int	color;

	c = stock->drawstartx - 1;
	while (++c < stock->drawendx)
	{
		stock->tex_x = (int)(256 *
				(c - (sprite_screen_x - stock->wall_height / 2))
				* SPRITE_SIDE / stock->wall_height) / 256;
		l = stock->wall_apex - 1;
		if (c > 0 && c < stock->r->x && transform_y > 0
				&& transform_y < stock->zbuffer[c])
		{
			while (++l < stock->wall_bottom)
			{
				stock->tex_y = (int)(l - stock->r->y / 2 + stock->wall_height
						/ 2) * SPRITE_SIDE / stock->wall_height;
				color = ft_tex_color(stock->tex_sprite,
						stock->tex_x, stock->tex_y);
				if (color != BLACK)
				{
					ft_put_pixel(stock, c, l, color);
				}
			}
		}
	}
}

/*
** FT_MEASURES_SPRITE : Calc draw start/end for x and y axes
*/

void	ft_measures_sprite(t_stock *stock, int sprite_screen_x)
{
	stock->wall_apex = stock->r->y / 2 - stock->wall_height / 2;
	if (stock->wall_apex < 0)
		stock->wall_apex = 0;
	stock->wall_bottom = stock->r->y / 2 + stock->wall_height / 2;
	if (stock->wall_bottom > stock->r->y)
		stock->wall_bottom = stock->r->y;
	stock->drawstartx = sprite_screen_x - stock->wall_height / 2;
	if (stock->drawstartx < 0)
		stock->drawstartx = 0;
	stock->drawendx = sprite_screen_x + stock->wall_height / 2;
	if (stock->drawendx > stock->r->x)
		stock->drawendx = stock->r->x;
}

/*
** Calculate intermediary variables and call drawing functions
** for stock->wall_height : "/ transformY" prevents fisheye effect
*/

void	ft_draw_sprite(t_stock *stock)
{
	int		i;
	double	inv;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;

	i = -1;
	while (++i < stock->nb_sprites)
	{
		stock->sprite_x = stock->sprite[stock->sp_order[i]].x
			- stock->player->pos_x;
		stock->sprite_y = stock->sprite[stock->sp_order[i]].y
			- stock->player->pos_y;
		inv = 1.0 / (stock->plane_x * stock->player->dir->y
				- stock->plane_y * stock->player->dir->x);
		transform_x = inv * (stock->player->dir->y * stock->sprite_x
				- stock->player->dir->x * stock->sprite_y);
		transform_y = inv * (stock->plane_x * stock->sprite_y
				- stock->plane_y * stock->sprite_x);
		sprite_screen_x = (int)((stock->r->x / 2)
				* (1 + transform_x / transform_y));
		stock->wall_height = abs((int)(stock->r->y / transform_y));
		ft_measures_sprite(stock, sprite_screen_x);
		ft_display_sprite(stock, transform_y, sprite_screen_x);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:18:32 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 20:46:45 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_put_pixel(t_stock *stock, int x, int y, unsigned int color)
{
	if (y > stock->r->y || x > stock->r->x || y < 0 || x < 0)
		return (ft_putstr("COLORING PIXEL FAILED : OUT OF THE MAP\n"));
	if (stock->shade < 0 && stock->hud == 0 && stock->k)
		stock->img->img_data_addr[(int)(y * stock->r->x) + x] =
			ft_color_mix(stock, color, stock->ray->dist_wall, y);
	else
		stock->img->img_data_addr[(int)(y * stock->r->x) + x] = color;
	return (0);
}

/*
** FT_TEX_DATA :
** wall_x est l abscisse de l'endroit du mur atteint
** tex_x est l ascisse de l'endroit correspondant sur la texture
** step_y : how much increase in texture for every screen pixel
*/

void	ft_tex_data(t_stock *stock, int a)
{
	double wall_x;
	double step_y;

	if (stock->ray->x_or_y == 'x')
		wall_x = stock->player->pos_y
			+ stock->ray->dist_wall * stock->ray->dir->y;
	else
		wall_x = stock->player->pos_x
			+ stock->ray->dist_wall * stock->ray->dir->x;
	wall_x -= floor(wall_x);
	stock->tex_x = wall_x * WALL_HEIGHT;
	if (stock->ray->x_or_y == 'x' && stock->ray->dir->x > 0)
		stock->tex_x = WALL_HEIGHT - stock->tex_x;
	if (stock->ray->x_or_y == 'y' && stock->ray->dir->y < 0)
		stock->tex_x = WALL_HEIGHT - stock->tex_x;
	step_y = WALL_HEIGHT / stock->wall_height;
	stock->tex_y = (a - (stock->r->y / 2 - stock->wall_height / 2)) * step_y;
	return ;
}

t_img	*ft_get_right_tex(t_stock *stock)
{
	if (stock->map->tab[stock->ray->mapy][stock->ray->mapx] == '1')
	{
		if (stock->ray->x_or_y == 'x')
		{
			if (stock->ray->dir->x < 0)
				return (stock->tex_e);
			else
				return (stock->tex_w);
		}
		else
		{
			if (stock->ray->dir->y < 0)
				return (stock->tex_s);
			else
				return (stock->tex_n);
		}
	}
	else
		return (stock->tex_po);
}

int		ft_build_col(t_stock *stock, int c)
{
	int		l;
	t_img	*tex;

	tex = ft_get_right_tex(stock);
	l = 0;
	while (l < stock->wall_apex)
		ft_put_pixel(stock, c, l++, ft_color(stock->mlx_ptr, stock->c));
	while (l < stock->wall_bottom)
	{
		ft_tex_data(stock, l);
		ft_put_pixel(stock, c, l,
				ft_tex_color(tex, stock->tex_x, stock->tex_y));
		l++;
	}
	while (l < stock->r->y)
		ft_put_pixel(stock, c, l++, ft_color(stock->mlx_ptr, stock->f));
	return (0);
}

/*
** zbuffer will be used for sprites
*/

int		ft_build_screen(t_stock *stock)
{
	int	c;

	if (!(stock->zbuffer = malloc(sizeof(double) * (stock->r->x))))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	c = 0;
	if (!(stock->ray->dir = malloc(sizeof(t_size))))
		return (ft_putstr("MALLOC FAILED - RAY DIR"));
	while (c <= stock->r->x)
	{
		ft_ray_dir_delta(stock, c);
		if (ft_build_col(stock, c))
			return (ft_putstr("PROBLEM IN BUILD COL FUNCTION (SCREEN FILE)\n"));
		stock->zbuffer[c] = stock->ray->dist_wall;
		c++;
	}
	ft_sprite(stock);
	ft_free_other(stock->zbuffer);
	ft_free_other(stock->ray->dir);
	ft_hud(stock);
	ft_lost_won(stock);
	return (0);
}

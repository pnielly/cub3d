/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:18:32 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/03 18:35:58 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_put_pixel(t_stock *stock, int x, int y, unsigned int color)
{
	if (y > stock->R->y || x > stock->R->x || y < 0 || x < 0)
	{
		printf("PUT PIXEL FAILED : OUT OF MAP ::::::x = %d, y = %d\n", x, y);
		printf("wall_apex = %d\n", stock->wall_apex);
		printf("stock->R->y = %f\n", stock->R->y);
		return (ft_putstr("COLORING PIXEL FAILED : OUT OF THE MAP\n"));
	}
	stock->img->img_data_addr[(int)(y * stock->R->x) + x] = color;
	return (0);
}

int	ft_build_col(t_stock *stock, int c)
{
	int	a;
	t_img	*tex;

	if (stock->hit == 'w')
	{
		/** Determine wall color **/
		if (stock->ray->x_or_y == 'x')
		{
			if (stock->ray->dir->x < 0)
				tex = stock->texE;
			else
				tex = stock->texW;
		}
		else
		{
			if (stock->ray->dir->y < 0)
				tex = stock->texS;
			else
				tex = stock->texN;
		}
	}
	/** penser a retirer d'ici >>> **/
	else if (stock->hit == 's')
		tex = stock->texSprite;
	else
		return (ft_putstr("DIDN'T HIT A WALL NEITHER A SPRITE\n"));
	/** <<< a la **/
	/** Color pixel on image **/
	a = 0;
	while (a < stock->wall_apex)
		ft_put_pixel(stock, c, a++, ft_color(stock->mlx_ptr, stock->C));
	while (a < stock->wall_bottom)
		{
			ft_tex_data(stock, a);
			ft_put_pixel(stock, c, a, ft_tex_color(tex, stock->texX, stock->texY));
			a++;
		}
	while (a < stock->R->y)
		ft_put_pixel(stock, c, a++, ft_color(stock->mlx_ptr, stock->F));
	return (0);
}

void	ft_tex_data(t_stock *stock, int a)
{
	/** wallX est l abscisse de l'endroit du mur atteint **/
	double wallX;
	/** texX est l ascisse de l'endroit correspondant sur la texture **/
	//	double texX;
	/** stepY : how much increase in texture for every screen pixel **/
	double stepY;

	if (stock->ray->x_or_y == 'x')
		wallX = stock->player->pos_y + stock->ray->dist_wall * stock->ray->dir->y;
	else
		wallX = stock->player->pos_x + stock->ray->dist_wall * stock->ray->dir->x;
	wallX -= floor(wallX);
	stock->texX = wallX * WALL_HEIGHT;
	if (stock->ray->x_or_y == 'x' && stock->ray->dir->x > 0)
		stock->texX = WALL_HEIGHT - stock->texX;
	if (stock->ray->x_or_y == 'y' && stock->ray->dir->y < 0)
		stock->texX = WALL_HEIGHT - stock->texX;
	stepY = WALL_HEIGHT / stock->wall_height;
	stock->texY = (a - (stock->R->y / 2 - stock->wall_height / 2)) * stepY;
	return ;
}

int	ft_build_screen(t_stock *stock)
{
	int	c;

	ft_new_image(stock);
	c = 0;
	while (c <= stock->R->x)
	{
		ft_ray_dir(stock, c);
		if (ft_build_col(stock, c))
			return (ft_putstr("PROBLEM IN BUILD COL FUNCTION (SCREEN FILE)\n"));
		/** zbuffer will be used for sprites **/
//		stock->zbuffer[c] = stock->ray->dist_wall;
		c++;
	}
	printf("PO\n");
//	ft_sprite(stock);
	return (0);
}

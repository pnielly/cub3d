/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:18:32 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/26 20:24:13 by pnielly          ###   ########.fr       */
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
	}
	if (color == ft_color(stock->mlx_ptr, stock->F))
		color = 1949632;
	stock->img->img_data_addr[(int)(y * stock->R->x) + x] = color;
	return (0);
}

static void	ft_build_col(t_stock *stock, int c)
{
	unsigned int	color;
	int	a;

	/** Determine wall color **/
	if (stock->ray->x_or_y == 'x')
	{
		if (stock->ray->dir->x < 0)
			color = COLOR_EAST;
		else
			color = COLOR_WEST;
	}
	else
	{
		if (stock->ray->dir->y < 0)
			color = COLOR_SOUTH;
		else
			color = COLOR_NORTH;
	}
	//	printf("BUILD COL\n");
	/** Color pixel on image **/
	a = 0;
	while (a < stock->wall_apex && a < stock->R->y)
		ft_put_pixel(stock, c, a++, ft_color(stock->mlx_ptr, stock->C));
	while (a < stock->wall_bottom && a < stock->R->y)
		ft_put_pixel(stock, c, a++, color);
	while (a < stock->R->y)
		ft_put_pixel(stock, c, a++, ft_color(stock->mlx_ptr, stock->F));
}

int	ft_build_screen(t_stock *stock)
{
	int	c;

	ft_new_image(stock);
//	printf("SCREEN2\n");
	c = 0;
//	printf("SCREEN\n");
	while (c <= stock->R->x)
	{
		ft_ray_dir(stock, c);
		ft_build_col(stock, c);
		c++;
//		printf("c = %d\n", c);
//		printf("x = %f, y = %f\n", stock->player->pos_x, stock->player->pos_y);
//		printf("wall_apex = %d\n, wall_bottom = %d\nwall_dist = %f\n", stock->wall_apex, stock->wall_bottom,stock->ray->dist_wall);
	}
	return (0);
}

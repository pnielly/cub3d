/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:07:58 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/27 12:16:14 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 ** ft_color only concerns ceiling and floor
*/

unsigned int	ft_color(void *mlx_ptr, t_color *zone)
{
	static int	color;

//	printf("color\n");
//	printf("zone->r = %u, zone->g = %u, zone->b = %u\n", zone->r, zone->g, zone->b);
	color = 0;
//	printf("color 1\n");
	color = color << 8;
//	printf("color 2\n");
	color = (color << 8) + zone->r;
//	printf("color 3\n");
	color = (color << 8) + zone->g;
//	printf("color 4\n");
	color = (color << 8) + zone->b;
//	printf("color 5\n");
	return (mlx_get_color_value(mlx_ptr, color));
}

/*
 ** ft_tex_color concerns wall textures
 ** (gives the color of each textured pixel)
*/

unsigned int	ft_tex_color(t_img *tex, int x, int y)
{
	return (tex->img_data_addr[y * WALL_HEIGHT + x]);
}

unsigned int	ft_color_mix(t_stock *stock,
		unsigned int color, double dist, int y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	v;

	if (dist > 2 && y > stock->wall_apex && y < stock->wall_bottom)
	{
		r = color / (16 * 16 * 16 * 16);
		g = (color / (16 * 16)) % (16 * 16);
		v = color % (16 * 16);
		r = FOG / (16 * 16 * 16 * 16) * (1 - 1 / dist * 0.2) + r / (dist / 2);
		g = ((FOG / (16 * 16)) % (16 * 16)) * (1 - 1 / dist * 0.2)
			+ g / (dist / 2);
		v = FOG % (16 * 16) * (1 - 1 / dist * 0.2) + v / (dist / 2);
		color = r * (16 * 16 * 16 * 16) + g * (16 * 16) + v;
	}
	return (color);
}

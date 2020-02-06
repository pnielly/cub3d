/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:34 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/06 18:35:16 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ray_dir(t_stock *stock, int c)
{
	int	mapx;
	int	mapy;
	int	hit;

	/** cameraX est le sens de rotation de la camera : prend valeur -1, 0 ou 1 **/
	stock->cameraX = c / (stock->R->x / 2) - 1;
	/** direction ray **/
	if (!(stock->ray->dir = malloc(sizeof(t_size))))
		return (ft_putstr("MALLOC FAILED - RAY DIR"));
	stock->ray->dir->x = stock->player->dir->x + stock->planeX * stock->cameraX;
	stock->ray->dir->y = stock->player->dir->y + stock->planeY * stock->cameraX;
	/** Delta dist : distance parcourue a chaque step **/
	stock->ray->delta_x = sqrt(1 + stock->ray->dir->y * stock->ray->dir->y / (stock->ray->dir->x * stock->ray->dir->x));
	stock->ray->delta_y = sqrt(1 + stock->ray->dir->x * stock->ray->dir->x / (stock->ray->dir->y * stock->ray->dir->y));
	/** residual distance et step (-1 ou 1) **/
	mapx = stock->player->pos_x;
	mapy = stock->player->pos_y;
	if (stock->ray->dir->x < 0)
	{
		stock->ray->res_x = stock->ray->delta_x * (stock->player->pos_x - mapx);
		stock->ray->step_x = -1;
	}
	else
	{
		stock->ray->res_x = stock->ray->delta_x * (mapx + 1 - stock->player->pos_x);
		stock->ray->step_x = 1;
	}
	if (stock->ray->dir->y < 0)
	{
		stock->ray->res_y = stock->ray->delta_y * (stock->player->pos_y - mapy);
		stock->ray->step_y = -1;
	}
	else
	{
		stock->ray->res_y = stock->ray->delta_y * (mapy + 1 - stock->player->pos_y);
		stock->ray->step_y = 1;
	}
	/** Perform DDA : the shorter res (x or y) gets incremented with corresponding delta **/
	hit = 0;
	while (!hit)
	{
		if (stock->ray->res_x < stock->ray->res_y)
		{
			stock->ray->res_x += stock->ray->delta_x;
			mapx += stock->ray->step_x;
			stock->ray->x_or_y = 'x';
		}
		else
		{
			stock->ray->res_y += stock->ray->delta_y;
			mapy += stock->ray->step_y;
			stock->ray->x_or_y = 'y';
		}
		if (stock->map->tab[mapy][mapx] == '1')
		{
			hit = 1;
			/** w = hit a wall */
			stock->hit = 'w';
		}
//		else if (stock->map->tab[mapy][mapx] == '2')
//		{
//			hit = 1;
//			 s = hit a sprite 
//			stock->hit = 's';
//		}
	}
	/** Calculate the adjusted distance (otherwise fisheye effect) **/
	if (stock->ray->x_or_y == 'x')
		stock->ray->dist_wall = (mapx - stock->player->pos_x + (1 - stock->ray->step_x) / 2) / stock->ray->dir->x;
	else
		stock->ray->dist_wall = (mapy - stock->player->pos_y + (1 - stock->ray->step_y) / 2) / stock->ray->dir->y;
	/** Calculate height of the wall**/
	stock->wall_height = stock->R->y / stock->ray->dist_wall;
//	printf("wall height = %d\n", stock->wall_height);
	/** Calculate the position of the top of the wall **/
	stock->wall_apex = stock->R->y / 2 - stock->wall_height / 2;
	if (stock->wall_apex < 0)
		stock->wall_apex = 0;
	/** Calculate the position of the bottom of the wall **/
	stock->wall_bottom = stock->R->y / 2 + stock->wall_height / 2;
	if (stock->wall_bottom >= stock->R->y)
		stock->wall_bottom = stock->R->y;
//	printf("wstart = %d, wend = %d, wall height = %f, dist = %f, mapx = %d, mapy = %d, posx = %f, posy = %f\n", stock->wall_apex, stock->wall_bottom, stock->wall_height, stock->ray->dist_wall, mapx, mapy, stock->player->pos_x, stock->player->pos_y);
	return (0);
}

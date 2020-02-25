/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:34 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 17:32:39 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** FT_MEASURES :
** Calculate the adjusted distance (otherwise fisheye effect)
** Calculate height of the wall
** Calculate the position of the top of the wall
** Calculate the position of the bottom of the wall
*/

void	ft_measures(t_stock *stock)
{
	if (stock->ray->x_or_y == 'x')
		stock->ray->dist_wall = (stock->ray->mapx - stock->player->pos_x
			+ (1 - stock->ray->step_x) / 2) / stock->ray->dir->x;
	else
		stock->ray->dist_wall = (stock->ray->mapy - stock->player->pos_y
			+ (1 - stock->ray->step_y) / 2) / stock->ray->dir->y;
	stock->wall_height = stock->r->y / stock->ray->dist_wall;
	stock->wall_apex = stock->r->y / 2 - stock->wall_height / 2;
	if (stock->wall_apex < 0)
		stock->wall_apex = 0;
	stock->wall_bottom = stock->r->y / 2 + stock->wall_height / 2;
	if (stock->wall_bottom >= stock->r->y)
		stock->wall_bottom = stock->r->y;
}

/*
** Perform Digital Differential Analysis
** The shorter res (x or y) gets incremented with corresponding delta
*/

void	ft_perform_dda(t_stock *stock)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (stock->ray->res_x < stock->ray->res_y)
		{
			stock->ray->res_x += stock->ray->delta_x;
			stock->ray->mapx += stock->ray->step_x;
			stock->ray->x_or_y = 'x';
		}
		else
		{
			stock->ray->res_y += stock->ray->delta_y;
			stock->ray->mapy += stock->ray->step_y;
			stock->ray->x_or_y = 'y';
		}
		if (stock->map->tab[stock->ray->mapy][stock->ray->mapx] == '1'
				|| (stock->map->tab[stock->ray->mapy]
				[stock->ray->mapx] == '3' && stock->shade < 0 && stock->k))
			hit = 1;
	}
}

void	ft_step_res(t_stock *stock)
{
	if (stock->ray->dir->x < 0)
	{
		stock->ray->res_x = stock->ray->delta_x
			* (stock->player->pos_x - stock->ray->mapx);
		stock->ray->step_x = -1;
	}
	else
	{
		stock->ray->res_x = stock->ray->delta_x
			* (stock->ray->mapx + 1 - stock->player->pos_x);
		stock->ray->step_x = 1;
	}
	if (stock->ray->dir->y < 0)
	{
		stock->ray->res_y = stock->ray->delta_y
			* (stock->player->pos_y - stock->ray->mapy);
		stock->ray->step_y = -1;
	}
	else
	{
		stock->ray->res_y = stock->ray->delta_y
			* (stock->ray->mapy + 1 - stock->player->pos_y);
		stock->ray->step_y = 1;
	}
}

/*
** Delta dist : distance parcourue a chaque step sur l'axe oppose
** cameraX est le sens de rotation de la camera : prend valeur -1, 0 ou 1
*/

int		ft_ray_dir_delta(t_stock *stock, int c)
{
	stock->camera_x = c / (stock->r->x / 2) - 1;
	stock->ray->dir->x = stock->player->dir->x
		+ stock->plane_x * stock->camera_x;
	stock->ray->dir->y = stock->player->dir->y
		+ stock->plane_y * stock->camera_x;
	stock->ray->delta_x = sqrt(1 + stock->ray->dir->y
		* stock->ray->dir->y / (stock->ray->dir->x * stock->ray->dir->x));
	stock->ray->delta_y = sqrt(1 + stock->ray->dir->x
		* stock->ray->dir->x / (stock->ray->dir->y * stock->ray->dir->y));
	stock->ray->mapx = stock->player->pos_x;
	stock->ray->mapy = stock->player->pos_y;
	ft_step_res(stock);
	ft_perform_dda(stock);
	ft_measures(stock);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:34 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 18:07:13 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ray_x(t_ray *ray, t_map *map)
{
	double	res;

	ray->step_y = 0;
	/** explications de la methode ici : http://projet-moteur-3d.e-monsite.com/pages/raycasting/raycasting.html **/
		while (map->tab[ray->pos_y + ray->sign_y * (ray->res_y + ray->step_y)][ray->pos_x + ray->sign_x * (ray->res_x + ray->step_y / tan(ray->dir))] != '1')
			ray->step_y++;
	/** residu **/
	res = sqrt(pow(stock->ray->res_x, 2) + pow(stock->ray->res_y, 2));
	/** on retourne la distance entre la position de la camera et la position du mur (detection horizontale) **/
	return (sqrt(pow(ray->step_y, 2) + pow(ray->step_y / tan(ray->dir), 2)) + res);
}

int	ft_ray_y(t_ray *ray, t_map *map)
{
	double	res;

	ray->step_x = 0;
	/** explications de la methode ici : http://projet-moteur-3d.e-monsite.com/pages/raycasting/raycasting.html **/
		while (map->tab[ray->pos_y + ray->sign_y * (ray->res_y + ray->step_x / tan(ray->step_x))][ray->pos_x + ray->sign_x * (ray->res_x + ray->step_x)] != '1')
			ray->step_x++;
	/** residual **/
	res = sqrt(pow(stock->ray->res_x, 2) + pow(stock->ray->res_y, 2));
	/** on retourne la distance entre la position de la camera et la position du mur (detection verticale) **/
	return (sqrt(pow(ray->step_x, 2) + pow(ray->step_x / tan(ray->dir), 2)) + res);
}

void	ft_raycasting(t_stock *stock)
{
	double	res_x;
	double	res_y;

	/** res = residual **/
	/** Si l'orientation est vers le haut, step_y devient negatif **/
	if (stock->ray->dir > M_PI)
	{
		stock->ray->res_y = ceil(stock->ray->pos_y) - stock->ray->pos_y;
		stock->ray->sign_y = 1;
	}
	else
	{
		stock->ray->res_y = stock->ray->pos_y - floor(stock->ray->pos_y);
		stock->ray->sign_y = -1;
	}
	/** Si l'orientation est vers la gauche, step_x devient negatif **/
	if (stock->ray->dir > M_PI / 2 && stock->ray->dir < 3 * M_PI / 2)
	{
		stock->ray->res_x = stock->ray->pos_x - floor(stock->ray->pos_x);
		stock->ray->sign_x = -1;
	}
	else
	{
		stock->ray->res_x = ceil(stock->ray->pos_x) - stock->ray->pos_x;
		stock->ray->sign_x = 1;
	}
	/** On garde la plus petite distance mesuree **/
	stock->ray->dist_wall = ft_min(ft_ray_x(stock->ray, stock->map), ft_ray_y(stock->ray, stock->map));
	/** Savoir quelle methode est la plus courte permet de connaitre le cote du wall **/
	if (ft_ray_x(stock->ray, stock->map) < ft_ray_y(stock->ray, stock->map))
		stock->ray->x_or_y = 'x';
	else
		stock->ray->x_or_y = 'y';
}

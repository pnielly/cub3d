/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:30:30 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/06 13:45:21 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_struct_ray(t_ray *ray)
{
	ray->res_x = 0;
	ray->res_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	return (0);
}

int	ft_init_struct_move(t_move *move)
{
	move->forward = 0;
	move->backward = 0;
	move->right = 0;
	move->left = 0;
	move->turn_right = 0;
	move->turn_left = 0;
	return (0);
}

int	ft_init_struct_stock(t_stock *stock)
{
	stock->wall_height = WALL_HEIGHT;
	stock->cam_height = stock->wall_height / 2;
	stock->cam_fov = CAM_FOV;
	stock->shade = 1;
	stock->life = 3;
	stock->lost = 0;
	stock->won = 0;
	stock->start_read_map = 0;
	stock->end_read_map = 0;
	stock->error = 0;
	if (!(stock->ray = malloc(sizeof(t_ray))))
		return (ft_putstr("MALLOC FAILED (RAY)\n"));
	ft_init_struct_ray(stock->ray);
	if (!(stock->move = malloc(sizeof(t_move))))
		return (ft_putstr("MALLOC FAILED (MOVE)\n"));
	ft_init_struct_move(stock->move);
	if (!(stock->player = malloc(sizeof(t_player))))
		return (ft_putstr("MALLOC FAILED (PLAYER)\n"));
	stock->nb_sprites = 0;
	return (0);
}

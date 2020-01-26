/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:30:30 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/26 21:20:43 by pnielly          ###   ########.fr       */
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
	move->up = 0;
	move->down = 0;
	move->right = 0;
	move->left = 0;
	move->turn_right = 0;
	move->turn_left = 0;
	return (0);
}

int	ft_init_struct_stock(t_stock *stock)
{
	/** wall data **/
	stock->wall_height = WALL_HEIGHT;
	/** camera data **/
	stock->cam_height = stock->wall_height / 2;
	stock->cam_fov = CAM_FOV;
	/** init data **/
	stock->escape = 0;
	/** ray data **/
	if (!(stock->ray = malloc(sizeof(t_ray))))
		return (ft_putstr("MALLOC FAILED (RAY)\n"));
	ft_init_struct_ray(stock->ray);
	/** move data **/
	if (!(stock->move = malloc(sizeof(t_move))))
		return (ft_putstr("MALLOC FAILED (MOVE)\n"));
	ft_init_struct_move(stock->move);
	/** malloc player **/
	if (!(stock->player = malloc(sizeof(t_player))))
		return (ft_putstr("MALLOC FAILED (PLAYER)\n"));
	return (0);
}

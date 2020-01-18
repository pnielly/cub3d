/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:43:18 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 17:34:02 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_wall_side_color(t_stock *stock, int c)
{
	/** find position of the wall (to determine its side) **/
	stock->rayed_wall_x = stock->player->pos_x + cos(c 
}

void	ft_build_walls(t_stock *stock, int c)
{
	int	y;

	/** Correction du "Fish Eye Effect" **/
	stock->ray->dist_wall *= cos(stock->cam_fov / stock->R.x * (stock->R.x / 2 - c));
	/** distance between camera and projection screen **/
	stock->dist_cam-screen = stock->R.x / 2 / tan(stock->cam_fov / 2);
	/** height of the projected column **/
	stock->wall_perceived_height = stock->wall_height * stock->dist_cam-screen / stock->ray->dist_wall;
	/** wall apex position **/
	stock->wall_apex = stock->R.y / 2 - stock->wall_perceived_height / 2;
	/** draw column c until from top screen to wall apex **/
	y = -1;
	while (++y =< stock_wall_apex)
		mlx_pixel_put(stock->mlx_ptr, stock->win_ptr, c, y, ft_get_color(stock->C->R, stock->C->G, stock->C->B));
	y = -1;
	/** draw column c from wall apex to wall bottom **/
	while (++y =< stock->wall_perceived_height)
		mlx_pixel_put(stock->mlx_ptr, stock->win_ptr, c, y, ft_wall_side_color(stock, c));
}

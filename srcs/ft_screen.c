/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:18:32 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 17:55:36 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_build_screen(t_stock *stock)
{
	int	c;

	c = 0;
	while (c <= stock->R.x)
	{
		stock->ray->dir = (stock->cam_dir - (stock->cam_fov / 2)) + c * (stock->cam_fov / stock->R.x);
		ft_raycasting(stock);
		ft_build_walls(stock, c);
		c++;
	}
}

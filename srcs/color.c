/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:07:58 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/24 14:52:55 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_color(void *mlx_ptr, t_color *zone)
{
	static int	color;

	color = 0;
	color = color << 8;
	color = (color << 8) + zone->R;
	color = (color << 8) + zone->G;
	color = (color << 8) + zone->B;
	return (mlx_get_color_value(mlx_ptr, color));
}

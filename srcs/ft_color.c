/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:07:58 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 17:22:01 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_get_color(int R, int G, int B)
{
	int	color;

	color = color << 8;
	color = (color << 8) + R;
	color = (color << 8) + G;
	color = (color << 8) + B;
	return (&color);
}


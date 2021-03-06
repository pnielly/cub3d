/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:33:19 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/04 14:14:56 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_new_tex(t_stock *stock, char *file)
{
	t_img	*tex;
	int		width;
	int		height;

	width = WALL_HEIGHT;
	height = WALL_HEIGHT;
	if (!(tex = malloc(sizeof(t_img))))
		return (NULL);
	if (!(tex->img_ptr = mlx_xpm_file_to_image(stock->mlx_ptr,
					file, &width, &height)))
		return (NULL);
	tex->img_data_addr = (int *)mlx_get_data_addr(tex->img_ptr,
			&tex->bpp, &tex->sizeline, &tex->endian);
	return (tex);
}

t_img	*ft_new_image(t_stock *stock)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	img->img_ptr = mlx_new_image(stock->mlx_ptr, stock->r->x, stock->r->y);
	img->img_data_addr = (int*)mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->sizeline, &img->endian);
	return (img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:29:29 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/26 20:22:23 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_new_image(t_stock *stock)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	img->img_ptr = mlx_new_image(stock->mlx_ptr, stock->R->x, stock->R->y);
	img->img_data_addr = (int*)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->sizeline, &img->endian);
	printf("LA\n");
	return (img);
}

int	ft_init_game(t_stock *stock)
{
	printf("INIT GAME0\n");
	if (!stock->R->x || !stock->R->y)
		return (ft_putstr("INCOMPLETE RESOLUTION\n"));
	if (stock->R->x > 2560)
		stock->R->x = 2560;
	if (stock->R->x < 0)
		return (ft_putstr("MAP RESOLUTION = 0\n"));
	if (stock->R->y > 1440)
		stock->R->y = 1440;
	if (stock->R->y < 0)
		return (ft_putstr("MAP RESOLUTION = 0\n"));
	/** mlx init **/
	if ((stock->mlx_ptr = mlx_init()) == NULL || (stock->win_ptr = mlx_new_window(stock->mlx_ptr, stock->R->x, stock->R->y, "Cub3d")) == NULL)
		return (ft_putstr("FAILED TO INIT MLX\n"));
	/** new image creation **/
	if (!(stock->img = ft_new_image(stock)))
		return (ft_putstr("MALLOC FAILED (IMG)"));
	return (0);
}

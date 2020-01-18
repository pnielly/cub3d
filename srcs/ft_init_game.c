/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:29:29 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 13:03:11 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_new_image(t_stock *stock)
{
	int	i;

	i = 24;
	if (!(stock->img_ptr = mlx_new_image(stock->mlx_ptr, stock->R->x, stock->R->y))
			|| !(stock->img_data_addr = mlx_get_data_addr(stock->img_ptr, &i, &stock->map->size_line, ENDIAN)))
		return (ft_putstr("IMAGE CREATION FAILED\n"));
	return (0);
}

int	ft_init_game(t_stock *stock)
{
	/** if resolution bigger than screen size, then resolution = screen size **/
	if (stock->R->x > 2560)
		stock->R->x = 2560;
	if (stock->R->y > 1440)
		stock->R->y = 1440;
	if (!stock->R->x || !stock->R->y)
		return (ft_putstr("INCOMPLETE RESOLUTION\n"));
	/** mlx init **/
	stock->mlx_ptr = mlx_init();
	stock->win_ptr = mlx_new_window(stock->mlx_ptr, stock->R->x, stock->R->y, "Cub3d");
	mlx_loop(stock->mlx_ptr);
	/** new image creation **/
	ft_new_image(stock);
	return (0);
}

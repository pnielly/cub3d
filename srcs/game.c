/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:29:29 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/05 12:44:53 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_game(t_stock *stock)
{
	printf("INIT GAME0\n");
	if (!stock->R->x || !stock->R->y)
		return (ft_putstr("INCOMPLETE RESOLUTION\n"));
	if (stock->R->x > SCREEN_WIDTH)
		stock->R->x = SCREEN_WIDTH;
	if (stock->R->x < 0)
		return (ft_putstr("MAP RESOLUTION = 0\n"));
	if (stock->R->y > SCREEN_HEIGHT)
		stock->R->y = SCREEN_HEIGHT;
	if (stock->R->y < 0)
		return (ft_putstr("MAP RESOLUTION = 0\n"));
	printf("TEXPRE\n");
	/** mlx init **/
	if ((stock->mlx_ptr = mlx_init()) == NULL)
		return (ft_putstr("FAILED TO INIT MLX\n"));
	printf("TEX\n");
	if ((stock->win_ptr = mlx_new_window(stock->mlx_ptr, stock->R->x, stock->R->y, "Cub3d")) == NULL)
		return (ft_putstr("FAILED TO INIT MLX\n"));
	/** new image creation **/
	if (!(stock->img = ft_new_image(stock)))
		return (ft_putstr("MALLOC FAILED (IMG)\n"));
	if (!(stock->texN = ft_new_tex(stock, stock->NO)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->texS = ft_new_tex(stock, stock->SO)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->texE = ft_new_tex(stock, stock->EA)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->texW = ft_new_tex(stock, stock->WE)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->texSprite = ft_new_tex(stock, stock->S)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	printf("TEX1\n");
	return (0);
}

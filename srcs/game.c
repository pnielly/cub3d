/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:29:29 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 17:35:44 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_level(int keycode, t_stock *stock)
{
	if (keycode == KEY_SPACE)
		ft_choose_level(stock);
	if (keycode == KEY_K)
		stock->k = 1;
	if (keycode == KEY_L)
		stock->k = 0;
	if (keycode == KEY_ESCAPE)
		return (ft_win_exit(stock));
	if (keycode == KEY_K || keycode == KEY_L)
		ft_loop(stock);
	return (0);
}

int		ft_choose_level(t_stock *stock)
{
	mlx_clear_window(stock->mlx_ptr, stock->win_ptr);
	mlx_hook(stock->win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &ft_win_exit, stock);
	mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 6, stock->r->y / 6, PINK, WELCOME);
	mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 6, stock->r->y / 4, PINK, KINDER);
	mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 6, stock->r->y / 4 * 3, PINK, LEGEND);
	mlx_hook(stock->win_ptr, KEYPRESS, KEYPRESSMASK, ft_level, stock);
	mlx_loop(stock->mlx_ptr);
	return (0);
}

int		ft_obj(t_stock *stock)
{
	mlx_hook(stock->win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &ft_win_exit, stock);
	mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 6, stock->r->y / 6, PINK, OBJ);
	mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 6, stock->r->y / 4, PINK, SUITE);
	mlx_hook(stock->win_ptr, KEYPRESS, KEYPRESSMASK, ft_level, stock);
	mlx_loop(stock->mlx_ptr);
	return (0);
}

int		check_resolution(t_stock *stock)
{
	if (!stock->r->x || !stock->r->y)
		return (ft_putstr("INCOMPLETE RESOLUTION\n"));
	if (stock->r->x > SCREEN_WIDTH)
		stock->r->x = SCREEN_WIDTH;
	if (stock->r->x < 0)
		return (ft_putstr("MAP RESOLUTION = 0\n"));
	if (stock->r->y > SCREEN_HEIGHT)
		stock->r->y = SCREEN_HEIGHT;
	if (stock->r->y < 0)
		return (ft_putstr("MAP RESOLUTION = 0\n"));
	return (0);
}

int		ft_init_game(t_stock *stock)
{
	if (check_resolution(stock))
		return (ft_putstr("WRONG RESOLUTION\n"));
	stock->life = (int)(stock->r->x / 64);
	if ((stock->mlx_ptr = mlx_init()) == NULL)
		return (ft_putstr("FAILED TO INIT MLX\n"));
	if ((stock->win_ptr = mlx_new_window(stock->mlx_ptr,
			stock->r->x, stock->r->y, "Cub3d")) == NULL)
		return (ft_putstr("FAILED TO INIT MLX\n"));
	if (!(stock->img = ft_new_image(stock)))
		return (ft_putstr("MALLOC FAILED (IMG)\n"));
	if (!(stock->tex_n = ft_new_tex(stock, stock->no)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->tex_s = ft_new_tex(stock, stock->so)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->tex_e = ft_new_tex(stock, stock->ea)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->tex_w = ft_new_tex(stock, stock->we)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->tex_po = ft_new_tex(stock, stock->po)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	if (!(stock->tex_sprite = ft_new_tex(stock, stock->s)))
		return (ft_putstr("MALLOC FAILED (TEX)\n"));
	return (0);
}

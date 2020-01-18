/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:21:08 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 17:22:08 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_win_exit(stock)
{
	mlx_destoy_image(stock->mlx_ptr, stock->img_ptr);
	mlx_clear_window(stock->mlx_ptr, stock->win_ptr);
	mlx_destroy_window(stock->mlx_ptr, stock->win_ptr);
}

void	ft_keypress(int keycode, stock)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		stock->move->up = 1;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		stock->move->down = 1;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		stock->move->right = 1;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		stock->move->left = 1;
}

void	ft_keyrelease(int keycode, stock)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		stock->move->up = 0;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		stock->move->down = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		stock->move->right = 0;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		stock->move->left = 0;
}

void	ft_process(t_stock *stock)
{
	mlx_destroy_image(stock->mlx_ptr, stock->img_ptr);
	ft_new_image(stock);
	ft_move(stock);
	ft_build_screen(stock);
}

void	ft_events(t_stock *stock)
{
	mlx_loop(stock->mlx_ptr);
	mlx_hook(stock->win_ptr, DestroyNotify, StructureNotifyMask, ft_win_exit, stock);
	mlx_hook(stock->win_ptr, KeyPress, KeyPressMask, ft_keypress, stock);
	mlx_hook(stock->win_ptr, KeyRelease, KeyReleaseMask, ft_keyrelease, stock);
	mlx_loop_hook(stock->mlx_ptr, ft_process, stock);
	ft_events(stock);
}

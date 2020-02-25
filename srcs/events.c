/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:21:08 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 17:29:34 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_win_exit(t_stock *stock)
{
	if (stock->img)
		ft_free_img(stock, stock->img);
	mlx_clear_window(stock->mlx_ptr, stock->win_ptr);
	mlx_destroy_window(stock->mlx_ptr, stock->win_ptr);
	ft_free_final(stock);
	system("killall afplay");
	exit(0);
	return (0);
}

int		ft_keypress(int keycode, t_stock *stock)
{
	if (keycode == KEY_W)
		stock->move->forward = 1;
	if (keycode == KEY_S)
		stock->move->backward = 1;
	if (keycode == KEY_D)
		stock->move->right = 1;
	if (keycode == KEY_A)
		stock->move->left = 1;
	if (keycode == KEY_RIGHT)
		stock->move->turn_right = 1;
	if (keycode == KEY_LEFT)
		stock->move->turn_left = 1;
	if (keycode == KEY_O)
		stock->shade *= -1;
	if (keycode == KEY_MAJ)
		stock->speed = SPEED * 2;
	if (keycode == KEY_ESCAPE)
	{
		stock->escape = 1;
		return (ft_win_exit(stock));
	}
//	if (keycode == KEY_W ||	keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
//		system("afplay bruit_pas.mp3 & ");
	return (0);
}

int		ft_keyrelease(int keycode, t_stock *stock)
{
	if (keycode == KEY_W)
		stock->move->forward = 0;
	if (keycode == KEY_S)
		stock->move->backward = 0;
	if (keycode == KEY_D)
		stock->move->right = 0;
	if (keycode == KEY_A)
		stock->move->left = 0;
	if (keycode == KEY_RIGHT)
		stock->move->turn_right = 0;
	if (keycode == KEY_LEFT)
		stock->move->turn_left = 0;
	if (keycode == KEY_MAJ)
		stock->speed = SPEED;
	if (keycode == KEY_ESCAPE)
		stock->escape = 1;
//	if (keycode == KEY_W ||	keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
//
	return (0);
}

int		ft_process(t_stock *stock)
{
	ft_free_img(stock, stock->img);
	if (!(stock->img = ft_new_image(stock)))
		return (ft_putstr("MALLOC FAILED (IMG)\n"));
	ft_move(stock);
	if (ft_build_screen(stock))
		return (ft_putstr("BUILD SCREEN FUNCTION FAILED\n"));
	mlx_put_image_to_window(stock->mlx_ptr, stock->win_ptr,
			stock->img->img_ptr, 0, 0);
	return (0);
}

int		ft_loop(t_stock *stock)
{
	mlx_hook(stock->win_ptr, DESTROYNOTIFY,
			STRUCTURENOTIFYMASK, &ft_win_exit, stock);
	mlx_hook(stock->win_ptr, KEYPRESS, KEYPRESSMASK, ft_keypress, stock);
	mlx_hook(stock->win_ptr, KEYRELEASE, KEYRELEASEMASK, ft_keyrelease, stock);
	mlx_loop_hook(stock->mlx_ptr, ft_process, stock);
	mlx_loop(stock->mlx_ptr);
	return (0);
}

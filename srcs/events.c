/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:21:08 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/03 18:37:30 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_win_exit(t_stock *stock)
{
	mlx_destroy_image(stock->mlx_ptr, stock->img->img_ptr);
	mlx_clear_window(stock->mlx_ptr, stock->win_ptr);
	mlx_destroy_window(stock->mlx_ptr, stock->win_ptr);
	exit(0);
	return (0);
}

int	ft_keypress(int keycode, t_stock *stock)
{
	if (keycode == KEY_W)
		stock->move->up = 1;
	if (keycode == KEY_S)
		stock->move->down = 1;
	if (keycode == KEY_D)
		stock->move->right = 1;
	if (keycode == KEY_A)
		stock->move->left = 1;
	if (keycode == KEY_RIGHT)
		stock->move->turn_right = 1;
	if (keycode == KEY_LEFT)
		stock->move->turn_left = 1;
	if (keycode == KEY_ESCAPE)
	{
		stock->escape = 1;
		printf("ON QUIT\n");
		mlx_destroy_image(stock->mlx_ptr, stock->img->img_ptr);
		mlx_clear_window(stock->mlx_ptr, stock->win_ptr);
		mlx_destroy_window(stock->mlx_ptr, stock->win_ptr);
	}
	return (0);
}

int	ft_keyrelease(int keycode, t_stock *stock)
{
	if (keycode == KEY_W)
		stock->move->up = 0;
	if (keycode == KEY_S)
		stock->move->down = 0;
	if (keycode == KEY_D)
		stock->move->right = 0;
	if (keycode == KEY_A)
		stock->move->left = 0;
	if (keycode == KEY_RIGHT)
		stock->move->turn_right = 0;
	if (keycode == KEY_LEFT)
		stock->move->turn_left = 0;
	if (keycode == KEY_ESCAPE)
		stock->escape = 1;
	return (0);
}

int	ft_process(t_stock *stock)
{
	ft_free_img(stock);
	if (!(stock->img = ft_new_image(stock)))
		return (ft_putstr("MALLOC FAILED (IMG)\n"));
	ft_move(stock);
	printf("LO\n");
	if (ft_build_screen(stock))
		return (ft_putstr("BUILD SCREEN FUNCTION FAILED\n"));
	printf("LO2\n");
	mlx_put_image_to_window(stock->mlx_ptr, stock->win_ptr, stock->img->img_ptr, 0, 0);
	return (0);
}

void	ft_events(t_stock *stock)
{
//	mlx_hook(stock->win_ptr, DestroyNotify, StructureNotifyMask, &ft_win_exit, stock);
	/** Key Event **/
	mlx_hook(stock->win_ptr, KeyPress, KeyPressMask, ft_keypress, stock);
	mlx_hook(stock->win_ptr, KeyRelease, KeyReleaseMask, ft_keyrelease, stock);
	/** when no event occurs **/
	mlx_loop_hook(stock->mlx_ptr, ft_process, stock);
	/** infinite loop that waits for an event **/
	mlx_loop(stock->mlx_ptr);
}

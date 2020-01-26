/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:42:18 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/24 14:04:42 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_stock *stock)
{
	double	old_dirX;
	double	old_planeX;

	/** move forward **/
	if (stock->move->up)
	{
		if (stock->map->tab[(int)stock->player->pos_y][(int)(stock->player->pos_x + stock->player->dir->x * SPEED)] == '0')
			stock->player->pos_x += stock->player->dir->x * SPEED;
		if (stock->map->tab[(int)(stock->player->pos_y + stock->player->dir->y * SPEED)][(int)stock->player->pos_x] == '0')
			stock->player->pos_y += stock->player->dir->y * SPEED;
	}
	/** move backwards **/
	if (stock->move->down)
	{
		if (stock->map->tab[(int)stock->player->pos_y][(int)(stock->player->pos_x - stock->player->dir->x * SPEED)] == '0')
			stock->player->pos_x -= stock->player->dir->x * SPEED;
		if (stock->map->tab[(int)(stock->player->pos_y - stock->player->dir->y * SPEED)][(int)stock->player->pos_x] == '0')
			stock->player->pos_y -= stock->player->dir->y * SPEED;
	}
	/** move right **/
	if (stock->move->right)
	{
		if (stock->map->tab[(int)stock->player->pos_y][(int)(stock->player->pos_x + stock->player->dir->y * SPEED)] == '0')
			stock->player->pos_x += stock->player->dir->y * SPEED;
		if (stock->map->tab[(int)(stock->player->pos_y - stock->player->dir->x * SPEED)][(int)stock->player->pos_x] == '0')
			stock->player->pos_y -= stock->player->dir->x * SPEED;
	}
	/** move left **/
	if (stock->move->left)
	{
		if (stock->map->tab[(int)stock->player->pos_y][(int)(stock->player->pos_x - stock->player->dir->y * SPEED)] == '0')
			stock->player->pos_x -= stock->player->dir->y * SPEED;
		if (stock->map->tab[(int)(stock->player->pos_y + stock->player->dir->x * SPEED)][(int)stock->player->pos_x] == '0')
			stock->player->pos_y += stock->player->dir->x * SPEED;
	}
	/** rotate right **/
	if (stock->move->turn_right)
	{
		old_dirX = stock->player->dir->x;
		stock->player->dir->x = stock->player->dir->x * cos(-SPEED_ROTATE) - stock->player->dir->y * sin(-SPEED_ROTATE);
		stock->player->dir->y = old_dirX * sin(-SPEED_ROTATE) + stock->player->dir->y * cos(-SPEED_ROTATE);
		old_planeX = stock->planeX;
		stock->planeX = stock->planeX * cos(-SPEED_ROTATE) - stock->planeY * sin(-SPEED_ROTATE);
		stock->planeY = old_planeX * sin(-SPEED_ROTATE) + stock->planeY * cos(-SPEED_ROTATE);
	}
	/** rotate left **/
	if (stock->move->turn_left)
	{
		old_dirX = stock->player->dir->x;
		stock->player->dir->x = stock->player->dir->x * cos(SPEED_ROTATE) - stock->player->dir->y * sin(SPEED_ROTATE);
		stock->player->dir->y = old_dirX * sin(SPEED_ROTATE) + stock->player->dir->y * cos(SPEED_ROTATE);
		old_planeX = stock->planeX;
		stock->planeX = stock->planeX * cos(SPEED_ROTATE) - stock->planeY * sin(SPEED_ROTATE);
		stock->planeY = old_planeX * sin(SPEED_ROTATE) + stock->planeY * cos(SPEED_ROTATE);
	}
}

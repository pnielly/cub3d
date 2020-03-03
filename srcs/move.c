/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:42:18 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 14:51:56 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turn_right(t_stock *stock)
{
	double	old_dirx;
	double	old_planex;

	if (stock->move->turn_right)
	{
		old_dirx = stock->player->dir->x;
		stock->player->dir->x = stock->player->dir->x *
			cos(-SPEED_ROTATE) - stock->player->dir->y * sin(-SPEED_ROTATE);
		stock->player->dir->y = old_dirx * sin(-SPEED_ROTATE)
			+ stock->player->dir->y * cos(-SPEED_ROTATE);
		old_planex = stock->plane_x;
		stock->plane_x = stock->plane_x * cos(-SPEED_ROTATE)
			- stock->plane_y * sin(-SPEED_ROTATE);
		stock->plane_y = old_planex * sin(-SPEED_ROTATE)
			+ stock->plane_y * cos(-SPEED_ROTATE);
	}
	if (stock->move->turn_right)
		stock->moved = 1;
}

void	ft_turn_left(t_stock *stock)
{
	double	old_dirx;
	double	old_planex;

	if (stock->move->turn_left)
	{
		old_dirx = stock->player->dir->x;
		stock->player->dir->x = stock->player->dir->x *
			cos(SPEED_ROTATE) - stock->player->dir->y * sin(SPEED_ROTATE);
		stock->player->dir->y = old_dirx * sin(SPEED_ROTATE)
			+ stock->player->dir->y * cos(SPEED_ROTATE);
		old_planex = stock->plane_x;
		stock->plane_x = stock->plane_x * cos(SPEED_ROTATE)
			- stock->plane_y * sin(SPEED_ROTATE);
		stock->plane_y = old_planex * sin(SPEED_ROTATE)
			+ stock->plane_y * cos(SPEED_ROTATE);
	}
	if (stock->move->turn_left)
		stock->moved = 1;
}

void	ft_move_left_right(t_stock *stock)
{
	if (stock->move->right)
	{
		if (ft_strchr("034", stock->map->tab[(int)stock->player->pos_y]
		[(int)(stock->player->pos_x + stock->player->dir->y * stock->speed)]))
			stock->player->pos_x += stock->player->dir->y * stock->speed;
		if (ft_strchr("034", stock->map->tab[(int)(stock->player->pos_y
					- stock->player->dir->x * stock->speed)]
				[(int)stock->player->pos_x]))
			stock->player->pos_y -= stock->player->dir->x * stock->speed;
	}
	if (stock->move->left)
	{
		if (ft_strchr("034", stock->map->tab[(int)stock->player->pos_y]
		[(int)(stock->player->pos_x - stock->player->dir->y * stock->speed)]))
			stock->player->pos_x -= stock->player->dir->y * stock->speed;
		if (ft_strchr("034", stock->map->tab[(int)(stock->player->pos_y +
		stock->player->dir->x * stock->speed)][(int)stock->player->pos_x]))
			stock->player->pos_y += stock->player->dir->x * stock->speed;
	}
	if (stock->move->left || stock->move->right)
		stock->moved = 1;
}

void	ft_move_for_back(t_stock *stock)
{
	if (stock->move->forward)
	{
		if (ft_strchr("034", stock->map->tab[(int)stock->player->pos_y]
		[(int)(stock->player->pos_x + stock->player->dir->x * stock->speed)]))
			stock->player->pos_x += stock->player->dir->x * stock->speed;
		if (ft_strchr("034", stock->map->tab[(int)(stock->player->pos_y
		+ stock->player->dir->y * stock->speed)][(int)stock->player->pos_x]))
			stock->player->pos_y += stock->player->dir->y * stock->speed;
	}
	if (stock->move->backward)
	{
		if (ft_strchr("034", stock->map->tab[(int)stock->player->pos_y]
		[(int)(stock->player->pos_x - stock->player->dir->x * stock->speed)]))
			stock->player->pos_x -= stock->player->dir->x * stock->speed;
		if (ft_strchr("034", stock->map->tab[(int)(stock->player->pos_y
		- stock->player->dir->y * stock->speed)][(int)stock->player->pos_x]))
			stock->player->pos_y -= stock->player->dir->y * stock->speed;
	}
	if (stock->move->forward || stock->move->backward)
		stock->moved = 1;
}

void	ft_move(t_stock *stock)
{
	stock->moved = 0;
	ft_move_for_back(stock);
	ft_move_left_right(stock);
	ft_turn_right(stock);
	ft_turn_left(stock);
	if (stock->map->tab[(int)stock->player->pos_y]
			[(int)stock->player->pos_x] == '3')
	{
		stock->player->pos_x = 2;
		stock->player->pos_y = 2;
		stock->life--;
		if (stock->life < 1)
		{
			stock->lost = 1;
			stock->life++;
		}
	}
	if (stock->map->tab[(int)stock->player->pos_y]
			[(int)stock->player->pos_x] == '4')
		stock->won = 1;
	ft_move_sprite(stock);
}

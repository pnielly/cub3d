/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:03:35 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/06 15:17:04 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_sprite2(t_stock *stock)
{
	if (stock->map->tab[(int)(stock->player->pos_y + 0.3)]
			[(int)stock->player->pos_x] == '2'
			&& stock->map->tab[(int)(stock->player->pos_y + 1.3)]
			[(int)stock->player->pos_x] == '0')
	{
		stock->map->tab[(int)(stock->player->pos_y + 0.3)]
			[(int)stock->player->pos_x] = '0';
		stock->map->tab[(int)(stock->player->pos_y + 1.3)]
			[(int)stock->player->pos_x] = '2';
	}
	if (stock->map->tab[(int)(stock->player->pos_y - 0.3)]
			[(int)stock->player->pos_x] == '2'
			&& stock->map->tab[(int)(stock->player->pos_y - 1.3)]
			[(int)stock->player->pos_x] == '0')
	{
		stock->map->tab[(int)(stock->player->pos_y - 0.3)]
			[(int)stock->player->pos_x] = '0';
		stock->map->tab[(int)(stock->player->pos_y - 1.3)]
			[(int)stock->player->pos_x] = '2';
	}
}

void	ft_move_sprite(t_stock *stock)
{
	if (stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x + 0.3)] == '2'
			&& stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x + 1.3)] == '0')
	{
		stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x + 0.3)] = '0';
		stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x + 1.3)] = '2';
	}
	if (stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x - 0.3)] == '2'
			&& stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x - 1.3)] == '0')
	{
		stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x - 0.3)] = '0';
		stock->map->tab[(int)stock->player->pos_y]
			[(int)(stock->player->pos_x - 1.3)] = '2';
	}
	ft_move_sprite2(stock);
}

/*
** sprite management : FT_BUBBLE SORT
** order from most far away to closer
** (will print the furthest away first)
*/

void	ft_bubble_sort(t_stock *stock, int tmp)
{
	int	i;

	i = -1;
	while (++i < stock->nb_sprites)
	{
		stock->sp_order[i] = i;
		stock->sp_dist[i] = pow(stock->player->pos_x - stock->sprite[i].x, 2)
			+ pow(stock->player->pos_y - stock->sprite[i].y, 2);
	}
	i = 0;
	while (i + 1 < stock->nb_sprites)
	{
		if (stock->sp_dist[stock->sp_order[i]]
				< stock->sp_dist[stock->sp_order[i + 1]])
		{
			tmp = stock->sp_order[i];
			stock->sp_order[i] = stock->sp_order[i + 1];
			stock->sp_order[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

/*
**  sprite management : FT_CHECK_SPRITES
**  distance from camera
*/

int		ft_check_sprites(t_stock *stock)
{
	int	i;
	int	j;
	int	rank;

	if (!(stock->sprite = malloc(sizeof(t_size) * (stock->nb_sprites + 1))))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	if (!(stock->sp_order = malloc(sizeof(int) * (stock->nb_sprites + 1))))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	if (!(stock->sp_dist = malloc(sizeof(double) * (stock->nb_sprites + 1))))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	rank = 0;
	j = -1;
	while (++j <= stock->map->nb_lines)
	{
		i = -1;
		while (++i <= stock->map->size_line)
		{
			if (stock->map->tab[j][i] == '2' || stock->map->tab[j][i] == '4')
			{
				stock->sprite[rank].x = i + 0.5;
				stock->sprite[rank++].y = j + 0.5;
			}
		}
	}
	return (0);
}

int		ft_sprite(t_stock *stock)
{
	int	tmp;

	if (ft_check_sprites(stock))
		return (ft_putstr("CHECK SPRITE FAILED\n"));
	tmp = 1;
	ft_bubble_sort(stock, tmp);
	ft_draw_sprite(stock);
	if (stock->sprite)
		ft_free_other(stock->sprite);
	if (stock->sp_order)
		free(stock->sp_order);
	if (stock->sp_dist)
		free(stock->sp_dist);
	return (0);
}

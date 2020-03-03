/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_won.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:46:53 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 14:40:30 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lost_won(t_stock *stock)
{
	if (stock->lost || stock->won)
	{
		mlx_clear_window(stock->mlx_ptr, stock->win_ptr);
		if (stock->lost)
		{
			mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 2,
					stock->r->y / 2, PINK, GAMEOVER);
			if (stock->k)
				mlx_string_put(stock->mlx_ptr, stock->win_ptr, 10,
						stock->r->y / 2 + stock->r->y / 12, PINK, TIPKINDER);
			if (!stock->k)
				mlx_string_put(stock->mlx_ptr, stock->win_ptr, 10,
						stock->r->y / 2 + stock->r->y / 12, PINK, TIPLEGEND);
		}
		else
		{
			mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 2,
					stock->r->y / 2, PINK, VICTORY);
			if (!stock->k)
				mlx_string_put(stock->mlx_ptr, stock->win_ptr, stock->r->x / 4,
						stock->r->y / 4 * 3, PINK, VIC_LEGEND);
		}
		mlx_loop(stock->mlx_ptr);
	}
}

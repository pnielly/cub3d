/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_won.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:46:53 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/25 18:24:17 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lost_won(t_stock *stock)
{
	if (stock->lost || stock->won)
	{
		if (stock->img)
			ft_free_img(stock, stock->img);
		mlx_clear_window(stock->mlx_ptr, stock->win_ptr);
		if (stock->lost)
		{
			ft_put_string(stock, GAMEOVER, stock->r->x / 2, stock->r->y / 2, PINK);
			if (stock->k)
				ft_put_string(stock, TIPKINDER, 10, stock->r->y / 2 + 50, PINK);
			if (!stock->k)
				ft_put_string(stock, TIPLEGEND, 10, stock->r->y / 2 + 50, PINK);
		}
		else
			ft_put_string(stock, VICTORY, stock->r->x / 2, stock->r->y / 2, PINK);
		mlx_loop(stock->mlx_ptr);
	}
}

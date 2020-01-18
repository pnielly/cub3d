/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:42:18 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/16 21:16:42 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_move(t_stock *stock)
{
	double	i;
	double	j;

	/** move forward **/
	i = cos(stock->player.dir) * stock->move->speed + stock->player->pos_x;
	j = sin(stock->player.dir) * stock->move->speed + stock->player->pos_y;
	if (stock->move->up)
	{
		if (stock->map->tab[j][i] == 0)
		{
			stock->player->pos_x = i;
			stock->player->pos_x = j;
		}
	}
	/** move backwards **/
	i = cos(stock->player.dir) * ((-1) * stock->move->speed) + stock->player->pos_x;
	j = sin(stock->player.dir) * ((-1) * stock->move->speed) + stock->player->pos_y;
	if (stock->move->down)
	{
		if (stock->map->tab[j][i] == 0)
		{
			stock->player->pos_x = i;
			stock->player->pos_x = j;
		}
	}
	/** rotate right **/
	if (stock->move->right)
		stock->player.dir += MP_I * stock->move->speed_rotate;
	/** rotate left **/
	if (stock->move->left)
		stock->player.dir += MP_I * stock->move->speed_rotate;
}

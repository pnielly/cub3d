/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:16:47 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/16 14:05:31 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_dir(char c)
{
	if (c = 'N')
		return (M_PI / 2);
	if (c = 'S')
		return (- M_PI / 2);
	if (c = 'E')
		return (M_PI);
	if (c = 'W')
		return (0);
}

int	ft_parsing(t_stock *stock)
{
	int	i;
	int	j;
	int	player;

	j = 0;
	player = 0;
	stock->map->nb_lines--;
	stock->map->size_line--;
	while (j <= stock->map->nb_lines)
	{
		i = 0;
		while (i <= stock->map->size_line)
		{
			/** checking walls around map **/
			if (i * j == 0 || i == stock->map->size_line || j == stock->map->nb_lines)
			{
				if (stock->map->tab[j][i] != '1')
					return (ft_putstr("MAP ISN'T SURROUNDED BY WALLS\n"));
			}
			/** checking for unauthorized char **/
			if (!ft_strchr("012NSEW", stock->map->tab[j][i]))
				return (ft_putstr("UNDEFINED CHARACTERS IN THE MAP\n"));
			/** checking for duplicate players **/
			if (player == 1 && ft_strchr("NSEW", stock->map->tab[j][i]))
				return (ft_putstr("MORE THAN ONE PLAYER STARTING POINT\n"));
			/** player initial position and orientation **/		
			if (!player && ft_strchr("NSEW", stock->map->tab[j][i]))
			{
				player = 1;
				stock->map->player.dir = ft_dir(stock->map->tab[j][i]);
				stock->map->player.pos_x = i;
				stock->map->player.pos_y = j;
			}
			/** object position **/
			if (stock->map->tab[j][i] == '2')
			{
				stock->sp_pos_x = i;
				stock->sp_pos_y = j;
			}
			i++;
		}
		j++;
	}
	if (!player)
		return (ft_putstr("PLAYER MISSING\n"));
	return (0);
}

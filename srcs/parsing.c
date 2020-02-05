/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:16:47 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/05 13:31:54 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_dir(t_stock *stock, char c)
{
	if (!(stock->player->dir = malloc(sizeof(t_size))))
		return (ft_putstr("MALLOC FAILED - PLAYER DIR"));
	if (c == 'N')
	{
		stock->player->dir->x = 0;
		stock->player->dir->y = -1;
		stock->plane_ory = 0;
		stock->plane_orx = 0.88;
	}
	if (c == 'S')
	{
		stock->player->dir->x = 0;
		stock->player->dir->y = 1;
		stock->plane_ory = 0;
		stock->plane_orx = 0.88;
	}
	if (c == 'E')
	{
		stock->player->dir->x = 1;
		stock->player->dir->y = 0;
		stock->plane_ory = 0.88;
		stock->plane_orx = 0;
	}
	if (c == 'W')
	{
		stock->player->dir->x = -1;
		stock->player->dir->y = 0;
		stock->plane_ory = 0.88;
		stock->plane_orx = 0;
	}
	return (0);
}

int	ft_parsing(t_stock *stock)
{
	int	i;
	int	j;
	int	start_pos;

	j = 0;
	start_pos = 0;
	stock->map->nb_lines--;
	stock->map->size_line--;
	while (j <= stock->map->nb_lines)
	{
		//		printf("tab[j] = %s\n", stock->map->tab[j]);
		i = 0;
		while (i <= stock->map->size_line)
		{
			printf("size_line = %d\n", stock->map->size_line);
			printf("i = %d, j = %d\n", i, j);
			printf("1\n");
			//			printf("tab[j][i] = %c\n", stock->map->tab[j][i]);
			/** checking walls around map **/
			if (i * j == 0 || i == stock->map->size_line || j == stock->map->nb_lines)
			{
				if (stock->map->tab[j][i] != '1')
					return (ft_putstr("MAP ISN'T SURROUNDED BY WALLS\n"));
			}
			printf("2\n");
			/** checking for unauthorized char **/
			if (!ft_strchr("012NSEW", stock->map->tab[j][i]))
				return (ft_putstr("UNDEFINED CHARACTERS IN THE MAP\n"));
			printf("3\n");
			/** checking for duplicate players **/
			if (start_pos == 1 && ft_strchr("NSEW", stock->map->tab[j][i]))
				return (ft_putstr("MORE THAN ONE PLAYER STARTING POINT\n"));
			printf("4\n");
			/** player initial position and orientation **/		
			if (!start_pos && ft_strchr("NSEW", stock->map->tab[j][i]))
			{
				start_pos = 1;
				ft_dir(stock, stock->map->tab[j][i]);
				/** plane = camera orientation : initial orientation determines <sign> and <value> **/
				stock->planeX = stock->player->dir->y * stock->plane_orx;
				stock->planeY = -stock->player->dir->x * stock->plane_ory;
				stock->player->pos_x = i + 0.5;
				printf("player->pos_x = %f\n", stock->player->pos_x);
				stock->player->pos_y = j + 0.5;
				printf("player->pos_y = %f\n", stock->player->pos_y);
				stock->map->tab[j][i] = '0';
			}
			printf("5\n");
			/** object position **/
			if (stock->map->tab[j][i] == '2')
				stock->nb_sprites++;
			i++;
		}
		j++;
	}
	if (!start_pos)
		return (ft_putstr("PLAYER MISSING\n"));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:03:35 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/05 16:43:14 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_sprite(t_stock *stock)
{
	int	i;
	double	spriteX;
	double	spriteY;
	double	inv;
	double	transformX;
	double	transformY;
	int	spriteScreenX;
	int	a;
	int	c;
	int	d;
	unsigned int	color;

	i = -1;
	while (++i < stock->nb_sprites)
	{
	printf("DRONE1\n");
		spriteX = stock->sprite[stock->sp_order[i]].x - stock->player->pos_x;
		spriteY = stock->sprite[stock->sp_order[i]].y - stock->player->pos_y;
		printf("spriteX = %f, spriteY = %f\n", spriteX, spriteY);
		inv = 1.0 / (stock->planeX * stock->player->dir->y - stock->planeY * stock->player->dir->x);
		transformX = inv * (stock->player->dir->y * spriteX - stock->player->dir->x * spriteY);
		transformY = inv * (stock->planeX * spriteY - stock->planeY * spriteX);
		spriteScreenX = (int)((stock->R->x / 2) * (1 + transformX / transformY));
		printf("transX = %f, transY = %f, spriteScreen = %d\n", transformX, transformY, spriteScreenX);
		/** calculate height of the sprite screen **/
	printf("DRONE2\n");
		stock->wall_height = abs((int)(stock->R->y / transformY));/** "/ transformY" prevents fisheye**/
		/** calculate lowest and highest pixel to fill in current stripe **/
	printf("DRONE3\n");
		stock->wall_apex = stock->R->y / 2 - stock->wall_height / 2;
		if (stock->wall_apex < 0)
			stock->wall_apex = 0;
		stock->wall_bottom = stock->R->y / 2 + stock->wall_height / 2;
		if (stock->wall_bottom > stock->R->y)
			stock->wall_bottom = stock->R->y;
		/** calculate width of the sprite (width = height here) **/
	printf("DRONE4\n");
		stock->drawStartX = spriteScreenX - stock->wall_height / 2;
		if (stock->drawStartX < 0)
			stock->drawStartX = 0;
		stock->drawEndX = spriteScreenX + stock->wall_height / 2;
		if (stock->drawEndX > stock->R->x)
			stock->drawEndX = stock->R->x;
		/** vertical stripe loop **/
	printf("DRONE5\n");
		c = stock->drawStartX;
		while (c < stock->drawEndX)
		{
			stock->texX = (int)(256 * (c - (spriteScreenX - stock->wall_height / 2)) * SPRITE_HEIGHT / stock->wall_height) / 256;
			a = stock->wall_apex;
			/** conditions of if :
			 * in the FOV (in front of camera, within limits)
			 * zbuffer with perpendicular distance **/
			if (c > 0 && c < stock->R->x && transformY > 0 && transformY < stock->zbuffer[c])
				/** loop on the current stripe **/
			{
//	printf("DRONE6\n");
				while (a < stock->wall_bottom)
				{
					d = (int)(a - stock->R->y / 2 + stock->wall_height / 2);
					stock->texY = d * SPRITE_HEIGHT / stock->wall_height;
					color = ft_tex_color(stock->texSprite, stock->texX, stock->texY);
					/** backrground is black, we don't want to print it **/
//	printf("DRONE7\n");
					if (color != BLACK)
						ft_put_pixel(stock, c, a, color);
					a++;
				}
			}
			c++;
		}
	}
	printf("DRONE\n");
}

int	ft_check_sprites(t_stock *stock)
{
	int	i;
	int	j;
	int	rank;

	printf("stock nb sprites = %d\n", stock->nb_sprites);
	if (!(stock->sprite = malloc(sizeof(int) * stock->nb_sprites)))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	printf("PAR ICI\n");
	if (!(stock->sp_order = malloc(sizeof(int) * stock->nb_sprites)))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	printf("PAR LA BAS\n");
	if (!(stock->sp_dist = malloc(sizeof(double) * (stock->nb_sprites))))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	rank = 0;
	j = 0;
	while (j <= stock->map->nb_lines)
	{
		i = 0;
		while (i <= stock->map->size_line)
		{
			if (stock->map->tab[j][i] == '2')
			{
				stock->sprite[rank].x = i + 0.5;
				stock->sprite[rank].y = j + 0.5;
				rank++;
			}
			i++;
		}
		j++;
	}
	printf("rank = %d\n", rank);
	return (0);
}

int	ft_sprite(t_stock *stock)
{
	int	i;
	int	check;
	int	tmp;

	/** looking for sprites locations **/
	if (ft_check_sprites(stock))
		return (ft_putstr("CHECK SPRITE FAILED\n"));
	printf("PAR LA BAS2\n");
	/** sprite management : distance from camera and order **/
	i = 0;
	while (i < stock->nb_sprites)
	{
		stock->sp_order[i] = i;
		stock->sp_dist[i] = pow(stock->player->pos_x - stock->sprite[i].x, 2) + pow(stock->player->pos_y - stock->sprite[i].y, 2);
		printf("stock->sp_dist[%d] = %f\n", i, stock->sp_dist[i]);
		printf("stock->nb_sprites = %d\n", stock->nb_sprites);
		i++;
	}
	printf("SORTI\n");
	/** bubble sort : distances from camera sorted from bigger to smaller **/
	check = 1;
	while (check)
	{
		check = 0;
		i = 0;
		printf("ici : stock->nb_sprites = %d\n", stock->nb_sprites);
			printf("dist[sp_order[0]] = %f,\n [1] = %f,\n [2] = %f\n", stock->sp_dist[0], stock->sp_dist[1], stock->sp_dist[2]);
		while (i + 1 < stock->nb_sprites)
		{
			if (stock->sp_dist[stock->sp_order[i]] < stock->sp_dist[stock->sp_order[i + 1]])
			{
				tmp = stock->sp_order[i];
				stock->sp_order[i] = stock->sp_order[i + 1];
				stock->sp_order[i + 1] = tmp;
				check = 1;
			}
			i++;
			printf("dist[sp_order[0]] = %f,\n [1] = %f,\n [2] = %f\n", stock->sp_dist[0], stock->sp_dist[1], stock->sp_dist[2]);
		}
	}
	printf("WALLAH\n");
	ft_draw_sprite(stock);
	return (0);
}

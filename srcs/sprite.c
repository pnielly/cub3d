

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

	i = 0;
	while (i < stock->nb_sprites)
	{
		spriteX = stock->sprite[stock->sp_order[i]].x - stock->player->pos_x;
		spriteY = stock->sprite[stock->sp_order[i]].y - stock->player->pos_y;
		inv = 1.0 / (stock->planeX * stock->player->dir->y - stock->planeY * stock->player->dir->x);
		transformX = inv * (stock->player->dir->y * spriteX - stock->player->dir->x * spriteY);
		transformY = inv * (stock->planeX * spriteY - stock->planeY * spriteX);
		spriteScreenX = (int)((stock->R->x / 2) * (1 + transformX / transformY));
		/** calculate height of the sprite screen **/
		stock->wall_height = abs((int)(stock->R->y / transformY));/** transformY prevents fisheye**/
		/** calculate lowest and highest pixel to fill in current stripe **/
		stock->wall_apex = stock->R->y / 2 - stock->wall_height / 2;
		if (stock->wall_apex < 0)
			stock->wall_apex = 0;
		stock->wall_bottom = stock->R->y / 2 + stock->wall_height / 2;
		if (stock->wall_bottom > stock->R->y)
			stock->wall_bottom = stock->R->y;
		/** calculate width of the sprite (width = height here) **/
		stock->drawStartX = stock->R->x / 2 - stock->wall_height / 2;
		if (stock->drawStartX < 0)
			stock->drawStartX = 0;
		stock->drawEndX = stock->R->x / 2 + stock->wall_height / 2;
		if (stock->drawEndX > stock->R->x)
			stock->drawEndX = stock->R->x;
		/** vertical stripe loop **/
		c = stock->drawStartX;
		while (c < stock->drawEndX)
		{
			stock->texX = (int)(256 * (c - (spriteScreenX - stock->wall_height / 2)) * SPRITE_HEIGHT / stock->wall_height) / 256;
			/** conditions of if : 
			 * in the FOV (in front of camera, within limits)
			 * zbuffer with perpendicular distance **/
			if (c > 0 && c < stock->R->x && transformY > 0 && transformY < stock->zbuffer[c])
				/** loop on the current stripe **/
				a = stock->wall_apex;
				while (a < stock->wall_bottom)
				{
					d = (int)(a - stock->R->y / 2 + stock->wall_height / 2);
					stock->texY = d * SPRITE_HEIGHT / stock->wall_height;
					color = ft_tex_color(stock->texSprite, stock->texX, stock->texY);
					/** backrground is black, we don't want to print it **/
					if (color != BLACK)
						ft_put_pixel(stock, c, a++, color);
				}
		}
		i++;
	}
}

int	ft_sprite(t_stock *stock)
{
	int	i;
	int	check;

	i = 0;
	if (!(stock->sp_order = malloc(sizeof(int) * stock->nb_sprites)))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	if (!(stock->sp_dist = malloc(sizeof(double) * stock->nb_sprites)))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	if (!(stock->zbuffer = malloc(sizeof(double) * stock->nb_sprites)))
		return (ft_putstr("MALLOC FAILED (SPRITE)\n"));
	while (i < stock->nb_sprites)
	{
		stock->sp_order[i] = i;
		stock->sp_dist[i] = pow(stock->player->pos_x - stock->sprite[i].x, 2) + pow(stock->player->pos_y - stock->sprite[i].y, 2);
		i++;
	}
	check = 1;
	while (check)
	{
		check = 0;
		i = 0;
		while (i < stock->nb_sprites - 1)
		{
			if (stock->sp_dist[i] < stock->sp_dist[i + 1])
			{
				stock->sp_order[i] = i + 1;
				stock->sp_order[i + 1] = i;
				check = 1;
			}
			i++;
		}
	}
	printf("WALLAH\n");
	ft_draw_sprite(stock);
	return (0);
}

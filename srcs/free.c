/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:19:51 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/05 16:54:55 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_final(t_stock *stock)
{
	free(stock->zbuffer);
	ft_free_img(stock, stock->texN);
	ft_free_img(stock, stock->texS);
	ft_free_img(stock, stock->texE);
	ft_free_img(stock, stock->texW);
	ft_free_img(stock, stock->texSprite);
	free(stock->C);
	free(stock->F);
	free(stock->R);
	free(stock->map->tab);
	free(stock->map);
	free(stock->sprite);
	free(stock->player->dir);
	free(stock->player);
	free(stock->move);
	free(stock->ray->dir);
	free(stock->ray);
	free(stock);
	return ;
}

void	ft_free_img(t_stock *stock, t_img *img)
{
	mlx_destroy_image(stock->mlx_ptr, img->img_ptr);
	free(img);
	stock->img = NULL;
}

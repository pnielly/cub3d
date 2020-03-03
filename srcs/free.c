/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:19:51 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 13:47:51 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_img(t_stock *stock, t_img *img)
{
	mlx_destroy_image(stock->mlx_ptr, img->img_ptr);
	free(img);
	img = NULL;
}

void	ft_free_other(void *other)
{
	if (other)
	{
		free(other);
		other = NULL;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_map(t_stock *stock)
{
	int	j;

	j = 0;
	while (j <= stock->map->nb_lines)
	{
		free(stock->map->tab[j]);
		stock->map->tab[j] = NULL;
		j++;
	}
	ft_free_other(stock->map->tab);
	ft_free_other(stock->map);
}

void	ft_free_final(t_stock *stock)
{
	ft_free_img(stock, stock->tex_n);
	ft_free_img(stock, stock->tex_s);
	ft_free_img(stock, stock->tex_e);
	ft_free_img(stock, stock->tex_w);
	ft_free_img(stock, stock->tex_po);
	ft_free_img(stock, stock->tex_sprite);
	ft_free_other(stock->c);
	ft_free_other(stock->f);
	ft_free_other(stock->r);
	ft_free_map(stock);
	ft_free_other(stock->player->dir);
	ft_free_other(stock->player);
	ft_free_other(stock->move);
	ft_free_other(stock->ray);
	ft_free_other(stock->no);
	ft_free_other(stock->so);
	ft_free_other(stock->we);
	ft_free_other(stock->ea);
	ft_free_other(stock->s);
	ft_free_other(stock->mlx_ptr);
	ft_free_other(stock);
	return ;
}

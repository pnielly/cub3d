/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:46:07 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/03 19:12:56 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_char(unsigned char *file, int start, int value)
{
	int	byte;

	byte = 3;
	while (byte >= 0)
	{
		file[start + byte] = (unsigned char)(value >> byte * 8);
		byte--;
	}
}

/*
** Source : Wikipedia : https://en.wikipedia.org/wiki/BMP_file_format
** FILE HEADER :
** padding > Each row in the Pixel array
**	is padded to a multiple of 4 bytes in size
** BITMAP FILE HEADER
** pos = 2 : size of bmp file in bytes : bmp file header = 14 et dib header = 40
** pos = 10 : starting address of pixel array
** DIB HEADER : BITMAPINFOHEADER (most common)
** pos = 14 : size of this header
** pos = 18 et 22 : bmp width and height in pixel
** pos = 26 : # of color planes (must be 1)
** pos = 28 : color depth
** pos = 30 : compression method : none (most common)
** pos = 34 : Image size (can be a dummy 0 for BI_RGB
** 	according to wikipedia page)
** pos = 38 et 42 : Horizontal & Vertical Resolution
**	of the image (pixel per metre)
** pos = 46 : # of colors in the color palette :
**	256 because 4 bytes per pixel
** pos = 50 : # of important colors used :
**	0 here because all are important
*/

void	ft_file_header(t_stock *stock)
{
	int			padding;
	int			size_headers;
	int			size_img;

	ft_bzero(stock->file_header, 54);
	padding = (4 - (((int)stock->r->x * BPP) % 4) % 4);
	stock->file_header[0] = 'B';
	stock->file_header[1] = 'M';
	size_headers = 14 + 40;
	size_img = (stock->r->y - 1) * ((int)stock->r->x + padding) * BPP;
	ft_char(stock->file_header, 2, size_img + size_headers);
	ft_char(stock->file_header, 10, size_headers);
	ft_char(stock->file_header, 14, 40);
	ft_char(stock->file_header, 18, (int)stock->r->x);
	ft_char(stock->file_header, 22, (int)stock->r->y);
	ft_char(stock->file_header, 26, 1);
	ft_char(stock->file_header, 28, COMPRESSION);
	ft_char(stock->file_header, 30, 0);
	ft_char(stock->file_header, 34, 0);
	ft_char(stock->file_header, 38, 1);
	ft_char(stock->file_header, 42, 1);
	ft_char(stock->file_header, 46, 256);
	ft_char(stock->file_header, 50, 0);
}

int		ft_write_img(t_stock *stock)
{
	int				i;
	int				j;
	unsigned char	rgb[3];

	j = -1;
	while (++j < (int)stock->r->y)
	{
		i = -1;
		while (++i < ft_min((int)stock->r->x, 2500))
		{
			rgb[0] = stock->img->img_data_addr[((int)stock->r->y - 1 - j)
					* (int)stock->r->x + i] >> 16;
			rgb[1] = stock->img->img_data_addr[((int)stock->r->y - 1 - j)
					* (int)stock->r->x + i] >> 8;
			rgb[2] = stock->img->img_data_addr[((int)stock->r->y - 1 - j)
					* (int)stock->r->x + i];
			if (write(stock->save_fd, rgb + 2, 1) < 0)
				return (ft_putstr("WRITE FAILED (SAVE BMP)\n"));
			if (write(stock->save_fd, rgb + 1, 1) < 0)
				return (ft_putstr("WRITE FAILED (SAVE BMP)\n"));
			if (write(stock->save_fd, rgb, 1) < 0)
				return (ft_putstr("WRITE FAILED (SAVE BMP)\n"));
		}
	}
	return (0);
}

/*
** BITMAP FILE HEADER : size = 14bytes & DIB HEADER : size = 40bytes
** HEADER PIXEL ARRAY : l'image se lit a l'envers (down-top + BGR)
*/

int		ft_screenshot(t_stock *stock)
{
	ft_build_screen(stock);
	if ((stock->save_fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0644)) < 0)
		return (ft_putstr("FAILED TO CREATE OR OPEN FILE (BMP SAVE)\n"));
	ft_file_header(stock);
	write(stock->save_fd, stock->file_header, 54);
	if (ft_write_img(stock))
		return (ft_putstr("WRITE IMG IN BITMAP FILE FAILED\n"));
	close(stock->save_fd);
	ft_free_img(stock, stock->img);
	if (!(stock->img = ft_new_image(stock)))
		return (ft_putstr("MALLOC FAILED (IMG)\n"));
	ft_free_final(stock);
	return (0);
}

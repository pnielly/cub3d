/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:46:07 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/05 16:56:40 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_char(unsigned char *start, int value)
{
	int	nbytes;
	
	nbytes = 4;
	while (nbytes-- > 0)
		start[nbytes] = (unsigned char)value >> (nbytes * 8);
	return (start);
}

unsigned char	*ft_file_header(t_stock *stock)
{
	static unsigned char	file_header[14 + 40];
	int			padding;

	ft_bzero(file_header, 54);
	/** Each row in the Pixel array is padded to a multiple of 4 bytes in size **/
	padding = 4 - ((int)stock->R->x % 4);
	/** BITMAP FILE HEADER **/
	/** si bug, caster en unsigned char **/
	file_header[0] = 'B';
	file_header[1] = 'M';
	/** size of bmp file in bytes : bmp file header = 14 et dib header = 40 **/
	ft_char(file_header + 2, (stock->img->bpp / 8) * (stock->R->y * (stock->R->x + padding)) + 14 + 40);
	/** starting address of pixel array **/
	ft_char(file_header + 10, 14 + 40);
	/** DIB HEADER : BITMAPINFOHEADER (most common) **/
	/** size of this header **/
	ft_char(file_header + 14, 40);
	/** bmp width and height in pixel **/
	ft_char(file_header + 18, (int)stock->R->x + padding);
	ft_char(file_header + 22, (int)stock->R->y);
	/** # of color planes (must be 1) **/
	ft_char(file_header + 26, 1);
	/** color depth **/
	ft_char(file_header + 28, stock->img->bpp);
	/** compression method : none (most common) **/
	ft_char(file_header + 30, 0);
	/** Image size (can be a dummy 0 for BI_RGB according to wiki page) **/
	ft_char(file_header + 34, 0);
	/** Horizontal & Vertical Resolution of the image (pixel per metre) **/
	ft_char(file_header + 38, 1);
	ft_char(file_header + 42, 1);
	/** # of colors in the color palette : 16 because 4 bytes per pixel **/
	ft_char(file_header + 46, 16);
	/** # of important colors used : 0 here because all are important **/
	ft_char(file_header + 50, 0);
	return (file_header);
}

int	ft_screenshot(t_stock *stock)
{
	int	i;
	int	j;
	int	rgb;
	
	printf("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqq\n");
	ft_build_screen(stock);
	printf("UUUUUUUUUUUUUUUUUUUUUUUUUUUUU\n");
	if ((stock->save_fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 777)) < 0)
		return (ft_putstr("FAILED TO CREATE OR OPEN FILE (BMP SAVE)\n"));
	/** BITMAP FILE HEADER : size = 14bytes & DIB HEADER : size = 40bytes **/
	write (stock->save_fd, ft_file_header(stock), 54);
	j = -1;
	while (++j < (int)stock->R->y)
	{
		i = -1;
	/** HEADER PIXEL ARRAY : l'image se lit a l'envers (down-top + BGR) **/
		while (++i < (int)stock->R->x)
		{
			if (write(stock->save_fd, &stock->img->img_data_addr[((int)stock->R->y - 1 - j) * (int)stock->R->x + i], 1) < 0)
				return (ft_putstr("WRITE FAILED (SAVE BMP)\n"));
//			rgb = stock->img->img_data_addr[((int)stock->R->y - j) * (int)stock->R->x + i] >> 24;
//			if (write(stock->save_fd, &rgb, 1) < 0)
//				return (ft_putstr("WRITE FAILED (SAVE BMP)\n"));
			rgb = stock->img->img_data_addr[((int)stock->R->y - 1 - j) * (int)stock->R->x + i] >> 8;
			if (write(stock->save_fd, &rgb, 1) < 0)
				return (ft_putstr("WRITE FAILED (SAVE BMP)\n"));
			rgb = stock->img->img_data_addr[((int)stock->R->y - 1 - j) * (int)stock->R->x + i] >> 16;
			if (write(stock->save_fd, &rgb, 1) < 0)
				return (ft_putstr("WRITE FAILED (SAVE BMP)\n"));
		}
	}
	close(stock->save_fd);
	ft_free_img(stock, stock->img);
	if (!(stock->img = ft_new_image(stock)))
		return (ft_putstr("MALLOC FAILED (IMG)"));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:45:11 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/03 18:37:36 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "libft.h"
# include "mlx.h"
/**# include "get_next_line.h"**/
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

/** EVENTS AND MASKS **/
# define KeyPress 2
# define KeyRelease 3
# define KeyPressMask 1
# define KeyReleaseMask 10
# define DestroyNotify 17
# define StructureNotifyMask 10001

/** KEYCODE **/
# define KEY_UP 126
# define KEY_W 13
# define KEY_DOWN 125
# define KEY_S 1
# define KEY_RIGHT 124
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_A 0
# define KEY_ESCAPE 53

/** colors walls **/
# define COLOR_NORTH 0x116CC7
# define COLOR_SOUTH 0xDD985C
# define COLOR_EAST 0xA91101
# define COLOR_WEST 0xEFD242
# define BLACK 0x000000

/** image data **/
# define CAM_FOV M_PI/3
# define WALL_HEIGHT 64
# define SPRITE_HEIGHT 64
# define SCREEN_WIDTH 2560
# define SCREEN_HEIGHT 1440

/** move data **/
# define SPEED 0.1
# define SPEED_ROTATE 0.1

/** A SUPPRIMER ?
typedef struct s_img
{
	void	*img_ptr;
}		t_img;

typedef struct s_list
{
	char	*content;
	t_list	*next;
}		t_list;
**/
typedef struct	s_size
{
	double	x;
	double	y;
}		t_size;

typedef struct s_color
{
	unsigned char	R;
	unsigned char	G;
	unsigned char	B;
	int		check;
}		t_color;

typedef struct	s_player
{
	t_size	*dir;
	double	pos_x;
	double	pos_y;
}		t_player;

typedef struct s_map
{
	char	**tab;
	int	nb_lines;
	int	size_line;
}		t_map;

typedef struct	s_move
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	turn_right;
	int	turn_left;
}		t_move;

typedef	struct	s_ray
{
	t_size	*dir;
	double	res_x;
	double	res_y;
	double	delta_x;
	double	delta_y;
	int	step_x;
	int	step_y;
	double	pos_x;
	double	pos_y;
	double	dist_wall;
	double	dist_wall_adj;
	char	x_or_y;
}		t_ray;

typedef struct	s_img
{
	int	bpp;
	int	endian;
	int	sizeline;
	void	*img_ptr;
	int	*img_data_addr;
}		t_img;

typedef struct	s_stock
{
	/** .cub data **/
	t_size	*R;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	t_color	*F;
	t_color	*C;
	/** map data **/
	t_map	*map;
	/** player data **/
	t_player	*player;
	/** camera data **/
	double	cam_height;
	double	cam_fov;
	double	plane_orx;
	double	plane_ory;
	double	planeX;
	double 	planeY;
	double	cameraX;
	/** raycasting data **/
	t_ray	*ray;
	char	hit;
	/** wall data **/
	double	wall_height;
	int	wall_apex;
	int	wall_bottom;
	/** init data **/
	void	*mlx_ptr;
	void	*win_ptr;
	int	escape;
	/** img data **/
	t_img	*img;
	t_img	*texN;
	t_img	*texS;
	t_img	*texE;
	t_img	*texW;
	t_img	*texSprite;
	/** -save **/
	int	save_fd;
	/** move data **/
	t_move	*move;
	/** tex data **/
	double	texX;
	double	texY;
	/** sprite data **/
	int	nb_sprites;
	t_size	*sprite;
	int	*sp_order;
	double	*sp_dist;
	int	drawStartX;
	int	drawEndX;
	double	*zbuffer;
}		t_stock;

/**int	main(int argc, char **argv);**/
int	get_next_line(int fd, char **line);
int	ft_putstr(char *str);
int	ft_check_map(t_stock *stock, char *file);
int	ft_parsing(t_stock *stock);
int	ft_init_game(t_stock *stock);
double	ft_min(double a, double b);
void	ft_events(t_stock *stock);
t_img	*ft_new_image(t_stock *stock);
t_img	*ft_new_tex(t_stock *stock, char *file);
void	ft_move(t_stock *stock);
int	ft_build_screen(t_stock *stock);
unsigned int	ft_color(void *mlx_ptr, t_color *zone);
void	ft_raycasting(t_stock *stock);
void	ft_move(t_stock *stock);
int	ft_init_struct_move(t_move *move);
int	ft_init_struct_stock(t_stock *stock);
int	ft_init_struct_ray(t_ray *ray);
int	ft_ray_dir(t_stock *stock, int c);
void	ft_free_img(t_stock *stock);
int	ft_screenshot(t_stock *stock);
unsigned int	ft_tex_color(t_img *tex, int x, int y);
void	ft_tex_data(t_stock *stock, int a);
int	ft_sprite(t_stock *stock);
int	ft_put_pixel(t_stock *stock, int x, int y, unsigned int color);

#endif

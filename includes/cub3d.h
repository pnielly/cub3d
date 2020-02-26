/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:45:11 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/26 10:43:31 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

/*
** EVENTS AND MASKS
*/
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 10
# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK 10001

/*
** KEYCODE
*/
# define KEY_UP 126
# define KEY_W 13
# define KEY_DOWN 125
# define KEY_S 1
# define KEY_RIGHT 124
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_A 0
# define KEY_O 31
# define KEY_MAJ 257
# define KEY_ESCAPE 53
# define KEY_K 40
# define KEY_L 37
# define KEY_SPACE 49

/*
** colors walls
*/
# define COLOR_NORTH 0x116CC7
# define COLOR_SOUTH 0xDD985C
# define COLOR_EAST 0xA91101
# define COLOR_WEST 0xEFD242
# define BLACK 0x000000
# define PINK 0x980088
# define FOG 0x000000

/*
** image data
*/
# define CAM_FOV 1.0472
# define WALL_HEIGHT 64
# define SPRITE_SIDE 64
# define SCREEN_WIDTH 2559
# define SCREEN_HEIGHT 1439
# define BPP 3
# define COMPRESSION 24

/*
** move data
*/
# define SPEED 0.1
# define SPEED_ROTATE 0.1

/*
** messages
*/
# define GAMEOVER "T'AS PERDU"
# define VICTORY "BRAVO, T'AS REUSSI"
# define WELCOME "BIENVENUE JEUNE AVENTURIER DE L'ARCHE PERDUE"
# define KINDER "APPUIE SUR < K > POUR LE NIVEAU KINDERGARTEN"
# define TIPKINDER "LA PROCHAINE FOIS, APPUIE SUR < O > =)"
# define LEGEND "APPUIE SUR < L > POUR LE NIVEAU LEGENDAIRE"
# define TIPLEGEND "POUR LE NIVEAU LEGENDAIRE, AIDE TOI DES COLONNES !"
# define OBJ "OBJECTIF : ATTEINDRE LA COLONNE ISOLEE"
# define SUITE "APPUIE SUR < ESPACE > POUR CONTINUER"
# define VIC_LEGEND "FELICITATIONS, T'ES UNE LEGENDE"

typedef struct	s_size
{
	double	x;
	double	y;
}				t_size;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				check;
}				t_color;

typedef struct	s_player
{
	t_size	*dir;
	double	pos_x;
	double	pos_y;
	int		start_pos;
}				t_player;

typedef struct	s_map
{
	char	**tab;
	int		nb_lines;
	int		size_line;
}				t_map;

typedef struct	s_move
{
	int	forward;
	int	backward;
	int	right;
	int	left;
	int	turn_right;
	int	turn_left;
}				t_move;

typedef	struct	s_ray
{
	t_size	*dir;
	double	res_x;
	double	res_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	pos_x;
	double	pos_y;
	int		mapx;
	int		mapy;
	double	dist_wall;
	double	dist_wall_adj;
	char	x_or_y;
}				t_ray;

typedef struct	s_img
{
	int		bpp;
	int		endian;
	int		sizeline;
	void	*img_ptr;
	int		*img_data_addr;
}				t_img;

/*
** stock->hud = 1 if the program is currently displaying the hud
** and 0 when it's done, so that the shade effect doesn't affect
** the hud (since it is made using sprites).
** stock->k = 1 if level is kindergarten / 0 if level is legend
*/

typedef struct	s_stock
{
	t_size			*r;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			*po;
	char			*texlife;
	t_color			*f;
	t_color			*c;
	t_map			*map;
	t_list			*list;
	t_player		*player;
	double			cam_height;
	double			cam_fov;
	double			plane_orx;
	double			plane_ory;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	t_ray			*ray;
	double			wall_height;
	int				wall_apex;
	int				wall_bottom;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*img;
	t_img			*tex_n;
	t_img			*tex_s;
	t_img			*tex_e;
	t_img			*tex_w;
	t_img			*tex_sprite;
	t_img			*tex_po;
	int				save_fd;
	unsigned char	file_header[14 + 40];
	t_move			*move;
	double			tex_x;
	double			tex_y;
	int				nb_sprites;
	t_size			*sprite;
	int				*sp_order;
	double			*sp_dist;
	int				drawstartx;
	int				drawendx;
	double			*zbuffer;
	double			sprite_x;
	double			sprite_y;
	int				shade;
	double			speed;
	int				life;
	t_img			*tex_life;
	int				hud;
	int				lost;
	int				won;
	int				k;
}				t_stock;

int				get_next_line(int fd, char **line);
int				ft_putstr(char *str);
int				ft_check_map(t_stock *stock, char *file);
int				ft_parsing(t_stock *stock);
int				ft_init_game(t_stock *stock);
double			ft_min(double a, double b);
double			ft_max(double a, double b);
int				ft_loop(t_stock *stock);
t_img			*ft_new_image(t_stock *stock);
t_img			*ft_new_tex(t_stock *stock, char *file);
void			ft_move(t_stock *stock);
int				ft_build_screen(t_stock *stock);
unsigned int	ft_color(void *mlx_ptr, t_color *zone);
int				ft_ray_dir_delta(t_stock *stock, int c);
int				ft_init_struct_move(t_move *move);
int				ft_init_struct_stock(t_stock *stock);
int				ft_init_struct_ray(t_ray *ray);
int				ft_ray_dir(t_stock *stock, int c);
void			ft_free_img(t_stock *stock, t_img *img);
int				ft_screenshot(t_stock *stock);
unsigned int	ft_tex_color(t_img *tex, int x, int y);
void			ft_tex_data(t_stock *stock, int a);
int				ft_sprite(t_stock *stock);
int				ft_put_pixel(t_stock *stock, int x, int y, unsigned int color);
void			ft_free_final(t_stock *stock);
void			ft_free_other(void *other);
void			ft_free_tab(char **tab);
int				ft_check_sprites(t_stock *stock);
void			ft_draw_sprite(t_stock *stock);
int				ft_assign(char *line, t_stock *stock, char **tab);
unsigned int	ft_color_mix(t_stock *stock, unsigned int color,
		double dist, int y);
void			ft_move_sprite(t_stock *stock);
int				ft_hud(t_stock *stock);
int				ft_keypress(int keycode, t_stock *stock);
int				ft_choose_level(t_stock *stock);
int				ft_win_exit(t_stock *stock);
int				ft_goal(t_stock *stock);
void			ft_lost_won(t_stock *stock);
int				ft_init_hud(t_stock *stock);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:45:11 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/18 17:57:55 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>

/** KEYCODE **/
# define KEY_UP 126
# define KEY_W 13
# define KEY_DOWN 125
# define KEY_S 1
# define KEY_RIGHT 124
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_A 0

/** colors walls **/
# define COLOR_NORTH 0xC7117F
# define COLOR_SOUTH 0x15DA21
# define COLOR_EAST 0xDA7A15
# define COLOR_WEST 0x15DAD7

/** image data **/
#define BPP 24
#define ENDIAN 0

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
	int	x;
	int	y;
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
	double	dir;
	double	pos_x;
	double	pos_y;
}		t_player;

typedef struct s_map
{
	char	**tab;
	t_list	*packing;
	int	nb_lines;
	int	size_line;
}		t_map;

typedef struct	s_move
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	speed;
}		t_move

typedef	struct	s_ray
{
	double	dir;
	double	res_x;
	double	res_y;
	int	sign_x;
	int	sign_y;
	double	pos_x;
	double	pos_y;
	double	dist_wall;
	double	dist_wall_adj;
	char	x_or_y;
}

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
	t_player	player;
	/** camera data **/
	double	cam_height;
	double	cam_dir;
	double	cam_fov;
	double	dist_cam-screen;
	/** raycasting data **/
	t_ray	*ray;
	/** wall data **/
	double	rayed_wall_x;
	double	rayed_wall_y;
	double	wall_height;
	double	wall_perceived_height;
	double	wall_apex;
	/** init data **/
	void	*mlx_ptr;
	void	*win_ptr;
	/** move data **/
	t_move	*move;
	/** image data **/
	void	*img_ptr;
	void	*img_data_addr;
	/** sprite data **/
	int	sp_pos_x;
	int	sp_pos_y;
}		t_stock;

/**int	main(int argc, char **argv);**/
int	get_next_line(int fd, char **line);
int	ft_putstr(char *str);
int	ft_check_map(t_stock *stock, char *file);
int	ft_parsing(t_stock *stock);
int	ft_init_game(t_stock *stock);
int	ft_min(double a, double b);

#endif

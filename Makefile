# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnielly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 16:12:05 by pnielly           #+#    #+#              #
#    Updated: 2020/03/11 12:24:18 by pnielly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

# directories
DIR_SRC = ./srcs
DIR_INC = ./includes
DIR_OBJ = ./obj
DIR_LIBFT = ./libft
DIR_MLX = ./minilibx_mms

# srcs files
SRC = main.c game.c events.c check_map.c check_map2.c check_map3.c color.c raycasting.c move.c parsing.c parsing2.c screen.c utils.c utils2.c init_struct.c image_tex.c save.c sprite.c draw_sprite.c free.c hud.c lost_won.c

# obj files
OBJ = $(addprefix $(DIR_OBJ)/,$(SRC:.c=.o))

# flags
FLAGS = -Wall -Werror -Wextra

# mlx library
LINK_MLX = -lmlx -framework OpenGL -framework AppKit -L $(DIR_MLX)
LIB_MLX = $(addprefix $(DIR_MLX)/,mlx.a)

# libft library
LIB_LIBFT = $(addprefix $(DIR_LIBFT)/,libft.a)
LINK_LIBFT = -L $(DIR_LIBFT) -l ft

# math library
LINK_MATH = -lm

all:	obj $(LIB_LIBFT) $(LIB_MLX) $(NAME)

obj:
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c
	gcc $(FLAGS) -I $(DIR_MLX) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

$(LIB_LIBFT):
	make -C $(DIR_LIBFT)

$(LIB_MLX):
	make -C $(DIR_MLX)
	mv $(DIR_MLX)/libmlx.dylib ./

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LINK_MLX) $(LINK_LIBFT) $(LINK_MATH) -o $(NAME)
	@echo
	@echo $(NAME) created !
	@echo

bonus:	fclean all

clean:
	/bin/rm -rf $(DIR_OBJ)
	make -C $(DIR_LIBFT) clean
	make -C $(DIR_MLX) clean

fclean:	clean
	/bin/rm -f $(NAME)
	/bin/rm -f *.bmp
	/bin/rm -f libmlx.dylib
	make -C $(DIR_LIBFT) fclean

re: fclean all

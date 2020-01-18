# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnielly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 16:12:05 by pnielly           #+#    #+#              #
#    Updated: 2020/01/15 22:15:15 by pnielly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# directories
DIR_SRC = ./srcs
DIR_INC = ./includes
DIR_OBJ = ./obj
DIR_LIBFT = ./libft
DIR_MLX = ./minilibx_mms

# srcs files
SRC = ./main.c ./ft_check_map.c ./ft_parsing.c ./ft_init_game.c ./ft_utils.c

# obj files
OBJ = $(addprefix $(DIR_OBJ)/,$(SRC:.c=.o))

# flags
FLAGS = -Wall -Werror -Wextra

# mlx library
ifeq ($(shell uname), Linux)
	LINK_MLX = -lmlx -lXest -lX11 -L $(DIR_MLX)
else
	LINK_MLX = -lmlx -framework OpenGL -framework AppKit -L $(DIR_MLX)
endif

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
	/bin/rm -f libmlx.dylib
	make -C $(DIR_LIBFT) fclean

re:	fclean all

.PHONY : all clean fclean re

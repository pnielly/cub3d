# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnielly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 20:52:56 by pnielly           #+#    #+#              #
#    Updated: 2020/01/28 14:14:15 by pnielly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = keycode

DIR_LIBFT = ../libft
DIR_MLX = ../minilibx_mms
DIR_X = ./

SRC = test.c

OBJ = test.o

#lib libft
LIB_LIBFT = $(addprefix $(DIR_LIBFT)/, libft.a)

#lib mlx
LIB_MLX = $(addprefix $(DIR_MLX)/, mlx.h)
LNK_MLX = -lmlx -framework OpenGL -framework AppKit -L $(DIR_MLX)

#lib X
INC_X = $(addprefix $(DIR_X)/, X.h)

all:	$(LIB_LIBFT) $(LIB_MLX) $(NAME)

$(LIB_LIBFT):
	make -C $(DIR_LIBFT)

$(LIB_MLX):
	make -C $(DIR_MLX)
	mv $(DIR_MLX)/libmlx.dylib ./

$(NAME):
	gcc $(SRC) $(INC_X) $(LNK_MLX) $(LIB_LIBFT)
	@echo
	@echo $(NAME) created !
	@echo

bonus:	fclean all

clean:
	/bin/rm -f *.o *.gch
	make -C $(DIR_LIBFT) clean
	make -C $(DIR_MLX) clean

fclean:	clean
	/bin/rm -f $(NAME)
	/bin/rm -f ../*.dylib
	make -C $(DIR_LIBFT) fclean

re:	fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnielly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 13:04:58 by pnielly           #+#    #+#              #
#    Updated: 2020/01/26 18:06:41 by pnielly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_tolower.c ./ft_toupper.c ./get_next_line.c ./ft_strxclude.c
OBJ = $(SRC:.c=.o)
SRC2 = ./ft_itoa.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strjoin.c ./ft_strmapi.c ./ft_strtrim.c ./ft_substr.c
OBJ2 = $(SRC2:.c=.o)
SRC3 = ./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstlast.c ./ft_lstmap.c ./ft_lstnew.c ./ft_lstsize.c
OBJ3 = $(SRC3:.c=.o)
HEADER = libft.h
FLAGS = -Wall -Werror -Wextra

all: bonus

$(NAME):bonus
	gcc $(FLAGS) -c $(SRC) $(SRC2) $(HEADER)
	ar rc $(NAME) $(OBJ) $(OBJ2)
	ranlib $(NAME)

bonus:	fclean
	gcc $(FLAGS) -c $(SRC) $(SRC2) $(SRC3) $(HEADER)
	ar rc $(NAME) $(OBJ) $(OBJ2) $(OBJ3)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o *.gch

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all

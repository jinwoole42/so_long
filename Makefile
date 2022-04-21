# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 18:06:20 by jinwoole          #+#    #+#              #
#    Updated: 2022/04/21 13:39:16 by jinwoole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME= so_long
MLX= libmlx.a
OPR_DIR	=	

SOURCES = ./main.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJECTS)
	arch -x86_64 $(CC) $(CFLAGS) -L. -lmlx -framework OpenGl -framework Appkit $(OBJECTS) -o so_long

$(MLX):
	make -C ./mlx
	cp ./mlx/libmlx.a .

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJ)
	make clean -C ./mlx

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX)
	$(RM) ./mlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re
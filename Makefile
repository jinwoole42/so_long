# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 18:06:20 by jinwoole          #+#    #+#              #
#    Updated: 2022/05/29 18:13:10 by jinwoole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME= so_long
MLX= libmlx.a

SOURCES =	main/main.c \
			main/read_map.c \
			main/render.c \
			main/num_render.c\
			error_check/name_check.c \
			error_check/shape_check.c \
			error_check/data_check.c \
			error_check/essential_check.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			game/key.c \
			game/move_up_down.c \
			game/move_lr.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJECTS)
	$(CC) $(CFLAGS) -L. -lmlx -framework OpenGl -framework Appkit $(OBJECTS) -o so_long

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
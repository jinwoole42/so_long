# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 18:06:20 by jinwoole          #+#    #+#              #
#    Updated: 2022/04/12 18:10:39 by jinwoole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME= so_long
OPR_DIR	=	

SOURCES =	

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

LIB:
	make -C ./minilibx
	cp ./minilibx/libmlx.a

$(NAME): LIB $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) libmlx.a -o push_swap

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJ)
## 라이브러리도 지워야
fclean: clean
	$(RM) $(NAME)

re: fclean all
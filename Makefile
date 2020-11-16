# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 14:38:42 by chzabakh          #+#    #+#              #
#    Updated: 2020/10/22 11:18:51 by chzabakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = ./src/main.c ./src/vec1.c ./src/vec2.c ./src/stock.c ./src/check.c \
      ./src/checktools.c ./src/tools.c ./get_next_line/get_next_line.c \
      ./src/normals.c ./src/start.c ./src/camera.c ./src/ray.c ./src/lish.c \
      ./src/clamp.c ./src/shapes.c

OBJ = $(SRC:.c=.o)

CC = gcc

INC = src/rtv1.h get_next_line/libft/libft.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(INC) $(OBJ)
		@make -C get_next_line/libft/
		@gcc  $(OBJ) get_next_line/libft/libft.a -o $(NAME) \
			-L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

clean:
		@make clean -C get_next_line/libft
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C get_next_line/libft
		@rm -f $(NAME)

re: fclean all

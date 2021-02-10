# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/02/10 19:15:50 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcamera.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/camera_coords.o $(OBJDIR)/new_ray.o
INC = ./includes/cam_function.h
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INC)
	@gcc $(CFlags) -c -o $@ $< -I $(INC)
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "CAMERA.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
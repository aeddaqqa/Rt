# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/03/07 18:01:14 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libnormals.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/normal_cone.o $(OBJDIR)/normal_plane.o $(OBJDIR)/normal_sphere.o\
$(OBJDIR)/normal_cylinder.o $(OBJDIR)/normal_parallelogram.o\
$(OBJDIR)/normal_box.o $(OBJDIR)/normal_triangle.o $(OBJDIR)/normal_ellipsoid.o\
$(OBJDIR)/normal_paraboloid.o $(OBJDIR)/normal_disk.o
INCS = ../../includes/normals/nor_functions.h
INC1 = ../../includes/functions.h
INC2 = ../../includes/define.h
INC5 = ../../includes/struct.h
INC3 = ../../includes/rt.h
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INCS) $(INC1) $(INC2) $(INC5) $(INC3)
	@gcc $(FLAGS) -c -o $@ $< -I $(INCS) 
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "NORMALS.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
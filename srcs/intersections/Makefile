# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/03/08 16:12:50 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libintersection.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/cone.o $(OBJDIR)/plane.o $(OBJDIR)/sphere.o\
$(OBJDIR)/cylinder.o $(OBJDIR)/box.o $(OBJDIR)/ellipsoid.o\
$(OBJDIR)/paraboloid.o $(OBJDIR)/parallelogram.o $(OBJDIR)/triangle.o\
$(OBJDIR)/utils.o $(OBJDIR)/disk.o $(OBJDIR)/slicer.o
INCS = ../../includes/
INC = ./includes/
INC1 = ../../includes/functions.h
INC2 = ../../includes/define.h
INC5 = ../../includes/struct.h
INC3 = ../../includes/rt.h
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INCS) $(INC1) $(INC2) $(INC5) $(INC3)
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I $(INCS) 
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "LIBINTERSECTION.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
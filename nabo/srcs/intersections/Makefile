# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/01/28 17:44:42 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libintersection.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/cone.o $(OBJDIR)/plane.o $(OBJDIR)/sphere.o\
$(OBJDIR)/cylinder.o $(OBJDIR)/box.o $(OBJDIR)/closest.o $(OBJDIR)/ellipsoid.o\
$(OBJDIR)/paraboloid.o $(OBJDIR)/parallelogram.o $(OBJDIR)/triangle.o\
$(OBJDIR)/utils.o

INCS = ../../includes/
INC = ./includes/
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INCS) $(INC)
	@gcc $(CFlags) -c -o $@ $< -I $(INC) -I $(INCS) 
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
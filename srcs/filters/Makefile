# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 17:22:57 by chzabakh          #+#    #+#              #
#    Updated: 2021/03/07 18:01:14 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfilters.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/antialiasing.o $(OBJDIR)/bmp.o $(OBJDIR)/cartoon.o\
$(OBJDIR)/grey.o $(OBJDIR)/negative.o $(OBJDIR)/noise.o\
$(OBJDIR)/sepia.o $(OBJDIR)/stereo.o $(OBJDIR)/blur.o 
INC = ../../includes/
INC1 = ../../includes/functions.h
INC2 = ../../includes/define.h
INC5 = ../../includes/struct.h
INC3 = ../../includes/rt.h
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INCS) $(INC1) $(INC2) $(INC5) $(INC3)
	@gcc $(FLAGS) -c -o $@ $< -I $(INC)
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "LIBFILTERS.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

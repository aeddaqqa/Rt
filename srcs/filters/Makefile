# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 17:22:57 by chzabakh          #+#    #+#              #
#    Updated: 2021/02/09 15:11:45 by chzabakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfilters.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/antialiasing.o $(OBJDIR)/bmp.o $(OBJDIR)/cartoon.o\
$(OBJDIR)/grey.o $(OBJDIR)/negative.o $(OBJDIR)/noise.o\
$(OBJDIR)/sepia.o $(OBJDIR)/stereo.o
INC = ../../includes/
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INC)
	@gcc $(CFlags) -c -o $@ $< -I $(INC)
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

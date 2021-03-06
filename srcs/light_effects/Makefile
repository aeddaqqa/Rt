# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/03/05 19:04:17 by chzabakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblights.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/ambient.o $(OBJDIR)/diffuse.o $(OBJDIR)/lights.o\
	 $(OBJDIR)/lights2.o $(OBJDIR)/shadows.o $(OBJDIR)/specular.o

INC = ../../includes/
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INC)
	@gcc $(CFlags) -c -o $@ $< -I $(INC)
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "LIBPARSE.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

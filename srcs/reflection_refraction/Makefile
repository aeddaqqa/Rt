# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/02/21 09:40:21 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = librender.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/calc_reflexion.o $(OBJDIR)/calc_refraction.o\
$(OBJDIR)/reflextion_color.o $(OBJDIR)/refraction_color.o\
$(OBJDIR)/render_ref_trsp.o
INC = ../../includes/
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INC)
	@gcc $(CFlags) -c -o $@ $< -I $(INC)
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "LIBRENDER.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
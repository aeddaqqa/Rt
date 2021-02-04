# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2021/01/30 18:52:37 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= RT
LIBFT = libft/libft.a

LIBPARSEDIR = srcs/parser
LIBPARSE = $(LIBPARSEDIR)/libparse.a

LIBCALCDIR = srcs/calculation
LIBCALC = $(LIBCALCDIR)/libcalculation.a

LIBNORMALDIR = srcs/normals
LIBNORMAL = $(LIBNORMALDIR)/libnormals.a

LIBINTERSECTDIR = srcs/intersections
LIBINTERSECT = $(LIBINTERSECTDIR)/libintersection.a

FLAGS= -Wall -Wextra -Werror
OBJDIR = objs
SRCDIR = srcs
OBJ= objs/main.o objs/new_ray.o
SRC= srcs/main.c
INC= includes/

all : Lib $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC)
	gcc $(FLAGS) -c -o $@ $< -I $(INC)
	
$(NAME) : $(LIBFT) $(LIBPARSE) $(LIBCALC) $(LIBNORMAL) $(LIBINTERSECT) $(OBJ)
	@gcc -o $@ $^ -lmlx -framework OpenGL -framework AppKit\
		-I $(INC)
	@printf "\033[0;32m"
	@printf "DONE COMPILING\n"
	@printf "\033[0m"

Lib :
	@mkdir $(OBJDIR) 2> /dev/null || true
	@make -C libft/
	@make -C $(LIBPARSEDIR)/
	@make -C $(LIBCALCDIR)/
	@make -C $(LIBNORMALDIR)/
	@make -C $(LIBINTERSECTDIR)/

clean :
	@rm -rf $(OBJDIR)
	@make -C libft/ clean
	@make -C $(LIBPARSEDIR)/ clean
	@make -C $(LIBCALCDIR)/ clean
	@make -C $(LIBNORMALDIR)/ clean
	@make -C $(LIBINTERSECTDIR)/ clean
	@printf "\033[0;32m"
	@printf "OBJ REMOVED\n"
	@printf "\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C $(LIBPARSEDIR)/ fclean
	@make -C $(LIBCALCDIR)/ fclean
	@make -C $(LIBNORMALDIR)/ fclean
	@make -C $(LIBINTERSECTDIR)/ fclean
	@printf "\033[0;32m"
	@printf "DONE CLEANING\n"
	@printf "\033[0m"

re : fclean all

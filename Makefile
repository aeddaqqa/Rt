# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 16:29:44 by aeddaqqa          #+#    #+#              #
#    Updated: 2021/03/06 16:54:47 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= RT
LIBFT = libft/libft.a

LIBPARSEDIR = srcs/parser
LIBPARSE = $(LIBPARSEDIR)/libparse.a

LIBLIGHTSDIR = srcs/light_effects
LIBLIGHTS = $(LIBLIGHTSDIR)/liblights.a

LIBRENDERDIR = srcs/reflection_refraction
LIBRENDER = $(LIBRENDERDIR)/librender.a

LIBFILTERSDIR = srcs/filters
LIBFILTERS = $(LIBFILTERSDIR)/libfilters.a

LIBCALCDIR = srcs/calculation
LIBCALC = $(LIBCALCDIR)/libcalculation.a

LIBCAMDIR = srcs/camera
LIBCAM = $(LIBCAMDIR)/libcamera.a

LIBNORMALDIR = srcs/normals
LIBNORMAL = $(LIBNORMALDIR)/libnormals.a

LIBINTERSECTDIR = srcs/intersections
LIBINTERSECT = $(LIBINTERSECTDIR)/libintersection.a

#FLAGS= -g
#FLAGS= -Wall -Wextra -Werror
FLAGS= -Wall -Wextra -Werror -g
OBJDIR = objs
SRCDIR = srcs
OBJ= objs/main.o objs/sdl.o objs/menu.o objs/objfile.o objs/core_raytracing.o objs/threads.o objs/hooks.o objs/draw.o
SRC= srcs/main.c srcs/sdl.c srcs/menu.c srcs/objfile.c srcs/core_raytracing.c objs/threads.c objs/hooks.c objs/draw.c
INC= includes/rt.h
INC1= includes/functions.h
INC2= includes/define.h
INC3= includes/struct.h

SDL =  `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf

all : Lib $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC) $(INC1) $(INC3) $(INC2)
	gcc $(FLAGS) -c -o $@ $< -I $(INC)

$(NAME) : $(LIBFT) $(LIBCALC) $(LIBPARSE) $(LIBCAM) $(LIBLIGHTS) $(LIBNORMAL) $(LIBINTERSECT)  $(LIBFILTERS) $(LIBRENDER) $(OBJ)
	@gcc $(FLAGS) -o $@ $^ $(SDL) -I $(INC)
	@printf "\033[0;32m"
	@printf "DONE COMPILING\n"
	@printf "\033[0m"

Lib :
	@mkdir $(OBJDIR) 2> /dev/null || true
	@make -C libft/
	@make -C $(LIBPARSEDIR)/
	@make -C $(LIBRENDERDIR)/
	@make -C $(LIBFILTERSDIR)/
	@make -C $(LIBCALCDIR)/
	@make -C $(LIBCAMDIR)/
	@make -C $(LIBNORMALDIR)/
	@make -C $(LIBINTERSECTDIR)/
	@make -C $(LIBLIGHTSDIR)/

clean :
	@rm -rf $(OBJDIR)
	@make -C libft/ clean
	@make -C $(LIBPARSEDIR)/ clean
	@make -C $(LIBRENDERDIR)/ clean
	@make -C $(LIBFILTERSDIR)/ clean
	@make -C $(LIBCALCDIR)/ clean
	@make -C $(LIBCAMDIR)/ clean
	@make -C $(LIBNORMALDIR)/ clean
	@make -C $(LIBINTERSECTDIR)/ clean
	@make -C $(LIBLIGHTSDIR)/ clean
	@printf "\033[0;32m"
	@printf "OBJ REMOVED\n"
	@printf "\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C $(LIBPARSEDIR)/ fclean
	@make -C $(LIBRENDERDIR)/ fclean
	@make -C $(LIBFILTERSDIR)/ fclean
	@make -C $(LIBCALCDIR)/ fclean
	@make -C $(LIBCAMDIR)/ fclean
	@make -C $(LIBNORMALDIR)/ fclean
	@make -C $(LIBINTERSECTDIR)/ fclean
	@make -C $(LIBLIGHTSDIR)/ fclean
	@printf "\033[0;32m"
	@printf "DONE CLEANING\n"
	@printf "\033[0m"

re : fclean all

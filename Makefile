# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: farwila <farwila@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/31 16:42:59 by aeddaqqa          #+#    #+#              #
#    Updated: 2021/03/01 21:20:39 by farwila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAM =  `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf

SRC = main.c intersection.c lights.c

all : 
	gcc $(SRC) -lm $(FRAM)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: farwila <farwila@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 20:16:38 by aeddaqqa          #+#    #+#              #
#    Updated: 2021/01/04 23:26:48 by farwila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes/rt.h

OBJ = srcs/main.o srcs/parse/load_file.o srcs/parse/free_parse.o srcs/parse/error_managment.o\
srcs/parse/init_p.o srcs/parse/main_pxml.o srcs/parse/init_s.o srcs/parse/stock_elements.o\
srcs/parse/utilfunc.o srcs/parse/utilfunctions.o srcs/parse/stock_elements_cmp.o srcs/parse/check_cmp.o\
srcs/parse/inner_text.o srcs/parse/get_cmp.o srcs/raytracing.o srcs/vect_calc.o

LIB = libft/libft.a

LIBOBJ	=	libft/ft_atoi.o libft/ft_itoa.o\
			libft/ft_memalloc.o libft/ft_putchar.o\
			libft/ft_putstr_fd.o libft/ft_strdup.o\
			libft/ft_strmap.o libft/ft_strpbrk.o\
			libft/ft_bzero.o libft/ft_lst_size.o\
			libft/ft_memccpy.o libft/ft_putchar_fd.o\
			libft/ft_strcat.o libft/ft_strequ.o\
			libft/ft_strmapi.o libft/ft_strrchr.o\
			libft/ft_isalnum.o libft/ft_lstadd.o\
			libft/ft_memchr.o libft/ft_putendl.o\
			libft/ft_strchr.o libft/ft_striter.o\
			libft/ft_strncat.o libft/ft_strsplit.o\
			libft/ft_isalpha.o libft/ft_lstdel.o\
			libft/ft_memcmp.o libft/ft_putendl_fd.o\
			libft/ft_strclr.o libft/ft_striteri.o\
			libft/ft_strncmp.o libft/ft_strstr.o libft/ft_isascii.o\
			libft/ft_lstdelone.o libft/ft_memcpy.o libft/ft_putlst.o\
			libft/ft_strcmp.o libft/ft_strjoin.o libft/ft_strncpy.o\
			libft/ft_strsub.o libft/ft_isdigit.o libft/ft_lstiter.o\
			libft/ft_memdel.o libft/ft_putnbr.o libft/ft_strcpy.o\
			libft/ft_strlcat.o libft/ft_strnequ.o libft/ft_strtrim.o\
			libft/ft_isgraph.o libft/ft_lstmap.o libft/ft_memmove.o\
			libft/ft_putnbr_fd.o libft/ft_strcspn.o libft/ft_strlcpy.o\
			libft/ft_strnew.o libft/ft_tolower.o libft/ft_isprint.o\
			libft/ft_lstnew.o libft/ft_memset.o libft/ft_putstr.o\
			libft/ft_strdel.o libft/ft_strlen.o libft/ft_strnstr.o\
			libft/ft_toupper.o libft/get_next_line.o

FRAM =  `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image

all : $(LIB) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<
$(NAME) : $(OBJ)
	$(CC) -o $@ $^ $(LIB) $(FRAM)

$(LIB) : $(LIBOBJ)
	@make -C libft/
	@printf "\033[0;32m"
	@printf "LIBFT.a CREATED\n"
	@printf "\033[0m"

clean :
	@echo "\033[2;32m"
	@rm -rf $(OBJ)   2> /dev/null || true
	@echo "Rt: all resources deleted"
	@echo "\033[0m"
fclean : clean 
	@echo "\033[2;34m"
	@rm -f $(NAME)  2> /dev/null || true
	@echo "DONE CLEANING\n"
	@echo "\033[0m"
	
re: fclean all

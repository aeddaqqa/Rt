# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2020/11/09 06:47:52 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= RTv1
LIB= libft/libft.a
FLAGS= -Wall -Wextra -Werror
LIBOBJ= libft/ft_atoi.o libft/ft_itoa.o\
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
OBJ= srcs/main.o srcs/destroy.o srcs/parsing.o srcs/camera.o\
	srcs/read.o srcs/vect_calc.o srcs/parse_lights.o\
	srcs/parse_objects.o srcs/vect_util.o\
	srcs/draw.o srcs/assert.o srcs/plane.o\
	srcs/sphere.o srcs/cylinder.o\
	srcs/cone.o srcs/lights.o\
	srcs/color.o srcs/rotation.o
	 
INC= includes/

all : $(LIB) $(NAME)

%.o : %.c $(INC)
	gcc $(FLAGS) -c -o $@ $< -I $(INC)
$(NAME) : $(OBJ)
	@gcc -o $@ $^ -lmlx -framework OpenGL -framework AppKit\
		-I $(INC) $(LIB)
	@printf "\033[0;32m"
	@printf "DONE COMPILING\n"
	@printf "\033[0m"

$(LIB) : $(LIBOBJ)
	@make -C libft/
	@printf "\033[0;32m"
	@printf "LIBFT.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@printf "\033[0;32m"
	@printf "OBJ REMOVED\n"
	@printf "\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@printf "\033[0;32m"
	@printf "DONE CLEANING\n"
	@printf "\033[0m"

re : fclean all

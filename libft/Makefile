# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 18:09:41 by nabouzah          #+#    #+#              #
#    Updated: 2021/03/07 18:01:14 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IN = libft.h
OBJ = ft_atoi.o ft_itoa.o ft_memalloc.o ft_putchar.o ft_putstr_fd.o ft_strdup.o\
	ft_strmap.o ft_strpbrk.o ft_bzero.o ft_lst_size.o ft_memccpy.o ft_putchar_fd.o\
	ft_strcat.o ft_strequ.o ft_strmapi.o ft_strrchr.o ft_isalnum.o ft_lstadd.o\
	ft_memchr.o ft_putendl.o ft_strchr.o ft_striter.o ft_strncat.o ft_strsplit.o\
	ft_isalpha.o ft_lstdel.o ft_memcmp.o ft_putendl_fd.o ft_strclr.o ft_striteri.o\
	ft_strncmp.o ft_strstr.o ft_isascii.o ft_lstdelone.o ft_memcpy.o ft_putlst.o\
	ft_strcmp.o ft_strjoin.o ft_strncpy.o ft_strsub.o ft_isdigit.o ft_lstiter.o\
	ft_memdel.o ft_putnbr.o ft_strcpy.o ft_strlcat.o ft_strnequ.o ft_strtrim.o\
	ft_isgraph.o ft_lstmap.o ft_memmove.o ft_putnbr_fd.o ft_strcspn.o ft_strlcpy.o\
	ft_strnew.o ft_tolower.o ft_isprint.o ft_lstnew.o ft_memset.o ft_putstr.o ft_strdel.o\
	ft_strlen.o ft_strnstr.o ft_toupper.o get_next_line.o
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

all	: $(NAME)

%.o : %.c $(IN)
	@gcc $(FLAGS) -c -o $@ $< -I $(IN)
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "LIBFT.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

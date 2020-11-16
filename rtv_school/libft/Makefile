# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 13:44:46 by ahkhilad          #+#    #+#              #
#    Updated: 2020/10/27 11:29:50 by ahkhilad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memcpy.c ft_striteri.c ft_memdel.c ft_strjoin.c ft_atoi.c \
	  ft_memmove.c ft_strlcat.c ft_bzero.c ft_memset.c ft_strlen.c \
	  ft_digitlen.c ft_putchar.c ft_strmap.c ft_isalnum.c ft_putchar_fd.c \
	  ft_strmapi.c ft_isalpha.c ft_putendl.c ft_strncat.c ft_isascii.c \
	  ft_putendl_fd.c ft_strncmp.c ft_isdigit.c ft_putnbr.c ft_strncpy.c \
	  ft_isprint.c ft_putnbr_fd.c ft_strnequ.c ft_itoa.c ft_putstr.c \
	  ft_strnew.c ft_lstadd.c ft_putstr_fd.c ft_strnstr.c ft_lstdel.c \
	  ft_sqrt.c ft_strrchr.c ft_lstdelone.c ft_strcat.c ft_strrev.c \
	  ft_lstiter.c ft_strchr.c ft_strsplit.c ft_lstmap.c ft_strclr.c \
	  ft_strstr.c ft_lstnew.c ft_strcmp.c ft_strsub.c ft_max.c ft_strcpy.c \
	  ft_strtrim.c ft_memalloc.c ft_strdel.c ft_tolower.c ft_memccpy.c \
	  ft_strdup.c ft_toupper.c ft_memchr.c ft_strequ.c \
	  ft_words_counter.c ft_memcmp.c ft_striter.c ft_atof.c ft_isnumber.c \
	  ft_str_is_numeric.c ft_point.c ft_atod.c

CC = gcc

INC = libft.h

CFLAG = -Wextra -Wall -Werror

EXEC = gcc $(CFLAG)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(EXEC) -c $(SRC)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

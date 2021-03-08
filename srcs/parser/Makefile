# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/03/08 16:48:48 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libparse.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./

OBJ= $(OBJDIR)/check_cmp.o $(OBJDIR)/check_forpobjects.o $(OBJDIR)/free_parse.o\
	$(OBJDIR)/init_p.o $(OBJDIR)/inner_text.o $(OBJDIR)/main_pxml.o\
	$(OBJDIR)/stock_elements_cmp.o $(OBJDIR)/utilfunctions.o\
	$(OBJDIR)/valid_all_cmp_pobjects.o $(OBJDIR)/valid_complex_objects.o\
	$(OBJDIR)/check_forcobjects.o $(OBJDIR)/error_managment.o $(OBJDIR)/get_cmp.o\
	$(OBJDIR)/init_s.o $(OBJDIR)/load_file.o $(OBJDIR)/stock_elements.o\
	$(OBJDIR)/utilfunc.o $(OBJDIR)/valid_all_cmp_cobjects.o\
	$(OBJDIR)/valid_cmp_fpart.o $(OBJDIR)/valid_principal_objects.o\
	$(OBJDIR)/read_cmp.o $(OBJDIR)/utilfunc2.o $(OBJDIR)/init_rt.o\
	$(OBJDIR)/init_ctags_cmp.o $(OBJDIR)/ft_atod.o $(OBJDIR)/stock_vect.o\
	$(OBJDIR)/rotation.o $(OBJDIR)/stock_components.o


INC = ../../includes/parser/pars_functions.h
INC1 = ../../includes/parser/pars_struct.h
INC2 = ../../includes/functions.h
INC3 = ../../includes/define.h
INC4 = ../../includes/rt.h
INC5 = ../../includes/struct.h
all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INCS) $(INC1) $(INC2) $(INC3) $(INC4) $(INC5)
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I $(INC1)
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

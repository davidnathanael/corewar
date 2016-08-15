# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/30 11:06:29 by tettouat          #+#    #+#              #
#    Updated: 2016/03/22 16:56:57 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

NAMEBASE =	libftprintf

LIB = ./libft/libft.a

FLAGS =	-Wall -Wextra -Werror

INCFLAG =  -I./includes

SRCDIR = srcs
OBJDIR = objs

SRC_NAME =	apply_flags.c												\
				apply_jz_modifier.c											\
				apply_lh_modifier.c											\
				apply_precision.c											\
				color.c														\
				flags.c														\
				format.c													\
				get_int_args.c												\
				get_other_args.c											\
				modifiers.c													\
				precision.c													\
				printf.c													\
				proceed.c													\
				proceed_int.c												\
				proceed_ptr.c												\
				proceed_str.c												\
				proceed_wide.c												\
				utils_wstr.c												\
				width.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRCDIR)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJDIR)/,$(OBJ_NAME))

.SILENT:

all: $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME): $(OBJ) $(LIB)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) please wait ...\033[0m\033[K"
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ /g`\033[0m\033[K"

$(OBJ): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	gcc $(FLAGS) -o $@ -c $< $(INCFLAG)

$(LIB):
	make -C libft/ fclean
	make -C libft/

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(OBJ)
	rm -f $(OBJDIR)/*.o
	make -C libft/ clean
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAMEBASE) is done\033[0m\033[K"

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(NAME)
	make -C libft/ fclean
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAMEBASE) is done\033[0m\033[K"

re: fclean all

.PHONY: fclean clean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/15 13:58:16 by ddela-cr          #+#    #+#              #
#    Updated: 2016/08/17 18:45:51 by vbaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc -I ../includes

FLAGS		=	-Wall -Wextra -Werror

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	../includes/

LIBFT_DIR	=	../libft/

LIBFT_LIB	=	../libft/libft.a

SRCBASE		=	\
				check_name_comment.c										\
				line_kind.c													\
				main.c														\
				parse.c														\
				ft_check_label.c											\
				ft_check_instr.c											\
				ft_error.c													\
				ft_end_name_comment.c										\
				check_file_name.c

INCBASE		=	\

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m - vbaudin \033[0m\033[K"
	echo "\r\033[38;5;15m - ddela-cr \033[0m\033[K"

$(OBJS):	$(SRCS) $(INCS)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) please wait ...\033[0m\033[K"
	mkdir -p $(OBJDIR)
	(cd $(OBJDIR);															\
	$(CC) $(FLAGS) -c $(addprefix ../, $(SRCS))								\
	-I $(addprefix ../, $(LIBFT_DIR)/$(INCDIR))								\
	-I $(addprefix ../, $(INCDIR)))

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) please wait ...\033[0m\033[K"
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124m🔘  FCLEAN $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

debug:		CC = cc
debug:		FLAGS += --analyze
debug:		re

.PHONY:		fclean clean re

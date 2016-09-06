# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 14:36:28 by ddela-cr          #+#    #+#              #
#    Updated: 2016/09/06 17:09:28 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAGS		=	-g -Wall -Wextra -Werror

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	../includes/

LIBFT_DIR	=	../libft/

LIBFT_LIB	=	../libft/libft.a

FTPRINTF_LIB	=	../ft_printf/libftprintf.a

SRCBASE		=	\
				and_or_xor_zjmp_ldi.c										\
				check_alive.c												\
				check_header.c												\
				doing_op.c													\
				dump.c														\
				exit_error.c												\
				fork_lfork_aff.c											\
				get_args.c													\
				get_champions.c												\
				init_vm.c													\
				introduce_champs.c											\
				launch_vm.c													\
				live_ld_st_add_sub.c										\
				load_champion.c												\
				main.c														\
				parse_command.c												\
				sti_lld_lldi.c												\
				utils.c

INCBASE		=	\

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(FTPRINTF_LIB)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJS):	$(SRCS) $(INCS)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) plz wait ...\033[0m\033[K"
	mkdir -p $(OBJDIR)
	(cd $(OBJDIR);															\
	$(CC) $(FLAGS) -c $(addprefix ../, $(SRCS))								\
	-I $(addprefix ../, $(LIBFT_DIR)/$(INCDIR))								\
	-I $(addprefix ../, $(INCDIR)))

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
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

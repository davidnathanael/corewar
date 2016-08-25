#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/07 15:14:14 by vbaudin           #+#    #+#              #
#    Updated: 2016/08/07 15:21:09 by vbaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
PRINTF = ./ft_printf/
LIB = ./libft/
ASM = ./asm/

MAKE = make -C

.SILENT:

all: asm libft
	echo "\033[38;5;44m☑️  ALL    $(NAME) is done\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m - vbaudin \033[0m\033[K"
	echo "\r\033[38;5;15m - ddela-cr \033[0m\033[K"
	echo "\r\033[38;5;15m - bbichero \033[0m\033[K"
	echo "\r\033[38;5;15m - ttridon \033[0m\033[K"

libft:
		$(MAKE) $(PRINTF)
		$(MAKE) $(LIB)

asm: libft
		$(MAKE) $(ASM)

clean:
		$(MAKE) $(LIB) clean
		$(MAKE) $(PRINTF) clean
		$(MAKE) $(ASM) clean

fclean:
		$(MAKE) $(LIB) fclean
		$(MAKE) $(PRINTF) fclean
		$(MAKE) $(ASM) fclean

re: fclean all

.PHONY: libft asm re all 

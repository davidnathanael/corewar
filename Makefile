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

PRINTF = ./ft_printf/
LIB = ./libft/
ASM = ./asm/

MAKE = make -C

all: asm libft

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

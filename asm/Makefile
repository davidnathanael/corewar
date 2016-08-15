# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/07 15:21:19 by vbaudin           #+#    #+#              #
#    Updated: 2016/08/15 12:02:39 by vbaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRCS = srcs/main.c

HEADERS = -I ../includes

OBJS = $(subst .c,.o,$(SRCS))

WFLAGS = -Wall -Werror -Wextra

cc = gcc

$(NAME): $(OBJS)
		$(CC) ../libft/libft.a $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: re flcean clean all

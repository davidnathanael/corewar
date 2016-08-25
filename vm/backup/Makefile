# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbichero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 16:15:39 by bbichero          #+#    #+#              #
#    Updated: 2016/08/25 14:36:15 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vm

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I includes -I ../includes

LDFLAGS = -L ../libft

LDLIBS = -lft

SRC_NAME = vm.c		list.c		check_byteCode.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(SRC:.c=.o)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

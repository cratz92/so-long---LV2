# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 14:40:03 by cbrito-l          #+#    #+#              #
#    Updated: 2021/08/13 15:26:31 by cbrito-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRCS := $(wildcard srcs/*.c)
OBJS := $(subst .c,.o,$(SRCS))
CFLAGS := -Wall -Wextra -Werror -Iincludes -Ilibft
CC := gcc

all: $(NAME)

bonus: $(NAME)

$(NAME): libft/libft.a ${OBJS}
		cp libft/libft.a $@
		ar rcs $@ ${OBJS}

libft/libft.a:
		make -C libft

clean:
		rm -f srcs/*.o
		make -C libft $@

fclean: clean
		rm -f ${NAME}
		make -C libft $@

re: fclean all

.PHONY: all bonus fclean clean re libft/libft.a

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 01:41:42 by cbrito-l          #+#    #+#              #
#    Updated: 2022/02/10 01:41:42 by cbrito-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRCS := $(wildcard srcs/*.c)
OBJS := $(subst .c,.o,$(SRCS))
CFLAGS := -Wall -Wextra -Werror -Iincludes -Ilibs/ft_printf -Ilibs/minilibx
MLXFLAGS := -L. -lXext -L. -lX11
CC := gcc


all: $(NAME)

$(NAME): libs/ft_printf/libftprintf.a libs/minilibx/libmlx.a ${OBJS}
		cp libs/ft_printf/libftprintf.a libs/minilibx/libmlx.a $@
		ar rcs $@ ${OBJS}

libs/ft_printf/libftprintf.a:
		make -C ft_printf

libs/minilibx/libmlx.a:
		make -C minilibx

clean:
		rm -f srcs/*.o
		make -C libs/ft_printf libs/minilibx $@

fclean: clean
		rm -f ${NAME}
		make -C libs/ft_printf libs/minilibx $@

re: fclean all

.PHONY: all bonus fclean clean re libs/ft_printf/libftprintf.a libs/minilibx/libmlx.a
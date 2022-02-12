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
CFLAGS := -Wall -Wextra -Werror -Iincludes -Ift_printf -Iminilibx
MLXFLAGS := -L. -lXext -L. -lX11
CC := gcc


all: $(NAME)

$(NAME): ft_printf/libftprintf.a minilibx/libmlx.a ${OBJS}
		cp ft_printf/libftprintf.a minilibx/libmlx.a $@
		ar rcs $@ ${OBJS}

./libs/ft_printf/libftprintf.a:
		make -C ft_printf

./libs/minilibx/libmlx.a:
		make -C minilibx

SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C libft

$(SERVER) : server.o error.o includes/minitalk.h
	@$(CC) server.o error.o $(LIBS) -o $@
	@printf "\e[38;5;226m./$@ successfully build🥑\e[0m\n"

clean:
		rm -f srcs/*.o
		make -C libs/ft_printf libs/minilibx $@

fclean: clean
		rm -f ${NAME}
		make -C libs/ft_printf libs/minilibx $@

re: fclean all

.PHONY: all bonus fclean clean re ./libs/ft_printf/libftprintf.a ./libs/minilibx/libmlx.a
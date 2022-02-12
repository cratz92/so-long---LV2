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

# -*- Definitions of variables -*-

NAME	= so_long

MINILIBDR	= minilibx_opengl/
OBJDR	= obj/
FTPRINTDR	= ft_printf/

MINILIB = libmlx.dylib
SOLONGLIB	= libso_long.a
HEADER	= includes/so_long.h

GAMESRC	= so_long.c
SRCS	= ${shell find src -type f -name "*.c"}
OBJS	= ${SRCS:src/%.c=obj/%.o}

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

# -*- The Rules -*-

#	Implicit rules

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

obj/%.o: src/%.c
			@echo "Compiling src source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

#	Active rules -g ${wildcard src/*.c} 

all:		$(NAME)

libx:
			@make --silent -C $(MINILIBDR)
			@make --silent -C $(FTPRINTDR)

$(NAME):	libx $(OBJDR) $(OBJS) $(HEADER)
			@ar rcs $(SOLONGLIB) $(OBJS)
			@echo "Compiling $(NAME)"
			@$(CC) $(CFLAGS) $(GAMESRC) $(SOLONGLIB) -L$(MINILIBDR) -lmlx -framework OpenGL -framework AppKit -L$(FTPRINTDR) -lftprintf -o $(NAME)
			#--------------------------------#
			@echo "Finished compiling $(NAME)"

bonus:		re $(NAME)

$(OBJDR):
			@mkdir -p $(OBJDR)

$(LIBOBJDR):
			@mkdir -p $(LIBOBJDR)

#	Cleaning rules

clean:
			@echo Removing all object files
			@rm -rf ${OBJDR}
			@rm -rf ${LIBOBJDR}

fclean:		clean
			@echo "Removing $(NAME) and $(SOLONGLIB)"
			@${RM} ${NAME} ${MINILIB} ${SOLONGLIB}
			@echo "Removing opengl library"
			@make -C ${MINILIBDR} clean
			@echo "Removing ft_printf library"
			@make -C ${FTPRINTDR} fclean

re:			fclean all

.PHONY:		all clean fclean re

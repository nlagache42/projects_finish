#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/14 14:36:53 by nlagache          #+#    #+#              #
#    Updated: 2016/09/19 18:31:04 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAG = -Wall -Wextra -Werror

NAME = fractol

SRC =	src/main.c \
		src/key_biding.c \
		src/zoom.c \
		src/utilities.c \
		src/init.c \
		src/mandelbrot.c \
		src/mandelbis.c \
		src/julia.c \
		src/burning_ship.c

OBJ = $(SRC:.c=.o)

MLX = ./inc/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		@make -C ./inc/minilibx_macos/
		@make -k -C libft
		@gcc $(FLAG) -o $(NAME) $(OBJ) $(MLX) -Llibft -lft
		@echo "$(NAME) created"

%.o: %.c
		@gcc $(FLAG) -c $< -o $@

clean:
		@make clean -k -C libft
		@make clean -C ./inc/minilibx_macos
		@rm -f $(OBJ)
		@echo "$(NAME) *.o deleted"

fclean: clean
		@make fclean -k -C libft
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re

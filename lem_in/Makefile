#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 13:25:54 by nlagache          #+#    #+#              #
#    Updated: 2017/02/01 12:40:46 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror

NAME = lem-in

DIR =	main.c \
		start_end.c \
		link.c \
		utils.c \
		road.c \
		send_ants.c \
		check_room.c \
		algo.c \
		error.c \

SRCS = $(addprefix srcs/, $(DIR))

OBJS = $(addprefix obj/, $(DIR:.c=.o))

LIBFT = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(FLAG) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS):
		$(CC) $(FLAGS) -c $(SRCS)
		@mkdir obj
		@mv $(DIR:.c=.o) ./obj/

$(LIBFT):
		make -C ./libft/

clean:
		@make clean -C libft
		@rm -rf ./obj
		@rm -rf $(DIR:.c=.o)
		@echo "$(NAME) .o deleted"

fclean: clean
		@make fclean -C libft
		rm -rf $(LIBFT) $(NAME)
		@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
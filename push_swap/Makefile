#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 13:25:54 by nlagache          #+#    #+#              #
#    Updated: 2016/11/16 12:48:37 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror

NAME_CHECKER = checker
NAME_SWAP = push_swap

DIR_CHECKER =	main.c \
				clist.c \
				sort_arg.c \
				swap.c \
				rotate.c \
				push.c \
				check_arg.c \
				check_arg_param.c \
				dblist.c

DIR_SWAP =		main.c \
				display.c \
				get_values.c \
				process.c \
				rules_a.c \
				rules_b.c \
				rules_c.c \
				sort_sample_list.c \
				easy_begin.c \
				push.c \
				get_arg.c \
				rotate_sort.c

SRC_SWAP = $(addprefix srcs/push_swap/, $(DIR_SWAP))
SRC_CHECKER = $(addprefix srcs/checker/, $(DIR_CHECKER))

OBJ_SWAP = $(addprefix obj_swap/, $(DIR_SWAP:.c=.o))
OBJ_CHECKER = $(addprefix obj_checker/, $(DIR_CHECKER:.c=.o))

LIBFT = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a
CC = gcc

all: $(NAME_CHECKER) $(NAME_SWAP)

$(NAME_CHECKER): $(LIBFT) $(OBJ_CHECKER)
		$(CC) $(FLAG) $(OBJ_CHECKER) $(LIBFT) -o $(NAME_CHECKER)

$(OBJ_CHECKER):
		$(CC) $(FLAGS) -c $(SRC_CHECKER)
		@mkdir obj_checker
		@mv $(DIR_CHECKER:.c=.o) ./obj_checker/

$(NAME_SWAP): $(LIBFT) $(OBJ_SWAP)
		$(CC) $(FLAG) $(OBJ_SWAP) $(LIBFT) $(PRINTF) -o $(NAME_SWAP)

$(OBJ_SWAP):
		$(CC) $(FLAGS) -c $(SRC_SWAP)
		@mkdir obj_swap
		@mv $(DIR_SWAP:.c=.o) ./obj_swap/

$(LIBFT):
		make -C ./libft/

clean:
		@make clean -C libft
		@rm -rf ./obj_swap ./obj_checker
		@rm -rf $(DIR_SWAP:.c=.o) $(DIR_CHECKER:.c=.o)
		@echo "$(NAME) ans $(NAME2) .o deleted"

fclean: clean
		@make fclean -C libft
		rm -rf $(LIBFT) $(NAME_SWAP) $(NAME_CHECKER)
		@echo "$(NAME) and $(NAME2) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
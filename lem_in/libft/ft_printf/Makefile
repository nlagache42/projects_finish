#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/13 18:35:21 by nlagache          #+#    #+#              #
#    Updated: 2016/11/14 10:25:37 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRC =	src/ft_apply_flags.c \
		src/ft_check.c \
		src/ft_dispatcher.c \
		src/ft_display_char.c \
		src/ft_display_numb.c \
		src/ft_flag_s.c \
		src/ft_flag_c.c \
		src/ft_flag_d.c \
		src/ft_flag_p_undefined.c \
		src/ft_flag_wu_wo.c \
		src/ft_flag_u_o.c \
		src/ft_flag_x.c \
		src/ft_handler.c \
		src/ft_printf.c \
		src/ft_buf.c \
		src/ft_transform_wchar.c \
		lib/ft_atoi.c \
		lib/ft_isdigit.c \
		lib/ft_itoa_base.c \
		lib/ft_strlen.c \
		lib/ft_strsub.c \
		lib/ft_wcharlen.c \
		lib/ft_strlwr.c \
		lib/ft_wstrlen.c \
		lib/ft_wstrsub.c

OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME) $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re
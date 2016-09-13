#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/01 15:56:29 by nlagache          #+#    #+#              #
#    Updated: 2016/09/01 22:40:23 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS =	./srcs/ft_printf.c\
		./srcs/check_and_replace_flags.c\
		./srcs/check_flags.c\
		./srcs/save_value.c\
		./srcs/save_value_2.c\
		./srcs/save_value_end.c\
		./srcs/save_value_char.c\
		./srcs/save_value_wildcard.c\
		./srcs/function_1.c\
		./srcs/function_2.c\
		./srcs/function_3.c\
		./srcs/libft/ft_bzero.c\
		./srcs/libft/ft_putstr.c\
		./srcs/libft/ft_putstr_fd.c\
		./srcs/libft/ft_strcat.c\
		./srcs/libft/ft_strcpy.c\
		./srcs/libft/ft_strdup.c\
		./srcs/libft/ft_strlen.c\
		./srcs/libft/ft_strnew.c\
		./srcs/libft/ft_memalloc.c\
		./srcs/libft/ft_putchar_fd.c\
		./srcs/libft/ft_strchr.c\
		./srcs/libft/ft_isalpha.c\
		./srcs/libft/ft_strcmp.c\

CFLAGS = -Wall -Werror -Wextra -I ./includes/

LIB = srcs/libft/libft.a

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make -C srcs/libft/
	ar rc $(NAME) $(OBJS) $(LIB)
	ranlib $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
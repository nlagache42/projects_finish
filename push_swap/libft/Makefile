#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 15:59:30 by nlagache          #+#    #+#              #
#    Updated: 2016/11/14 15:25:02 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS_MEM = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
		ft_memdel.c ft_memdel2.c
SRCS_STR = ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		ft_strcmp.c ft_strncmp.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_strdel.c ft_strnew.c ft_strndup.c \
		ft_strclen.c
SRCS_FCT = ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
		ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
		ft_atoi_int.c ft_count_nbr.c ft_intdup.c ft_swap.c \
		ft_strisdigit.c
SRCS_LST = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c

CC = gcc
SRCS = $(SRCS_MEM) $(SRCS_STR) $(SRCS_FCT) $(SRCS_LST)
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./ft_printf/
		ar r $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJS):
		$(CC) $(FLAGS) -c -I./ $(SRCS)

clean:
		$(RM) $(OBJS)
		make fclean -C ./ft_printf/

fclean: clean
		$(RM) $(NAME) $(FT_PRINTF)

re: fclean all

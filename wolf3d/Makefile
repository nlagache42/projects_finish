#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/04 11:47:09 by nlagache          #+#    #+#              #
#    Updated: 2016/10/11 10:20:08 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
CYA =		\033[36m
STD =		\033[39m

NAME =		wolf3d

IDIR =		./incs/

SDIR =		./srcs/
SRCS =		$(shell ls srcs/)

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

FLAG =		-O3 -Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBCC)
	@make -C ./libft/
	@gcc $(FLAG) $(OBCC) ./libft/libft.a -I./incs/ -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@echo "Compil ->${STD} $^"
	@gcc $^ $(FLAG) -c -o $@

header:
	@mkdir -p $(ODIR)
	@echo "${YEL}"
	@echo "WOLF 3D"
	@echo "${STD}"

clean: header
	@echo "  ${RED}Rm all .o${STD}"
	@rm -rf $(OBCC)

fclean: clean
	@echo "  ${RED}Rm $(NAME)${STD}"
	@make -C ./libft/ fclean
	@rm -f $(NAME)

.PHONY: all $(NAME) $(ODIR)%.o header norme clean fclean re

re: fclean all

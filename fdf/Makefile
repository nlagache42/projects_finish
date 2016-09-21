#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 11:31:31 by nlagache          #+#    #+#              #
#    Updated: 2016/09/20 11:19:10 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRCS =	./srcs/color.c\
		./srcs/convert.c\
		./srcs/coordmap.c\
		./srcs/draw_tab.c\
		./srcs/draw_lines.c\
		./srcs/list_lenght.c\
		./srcs/mlx_setup.c\
		./srcs/list_to_tab.c\
		./srcs/read.c\
		./srcs/error.c\
		./srcs/main.c

OBJ =	color.o\
		convert.o\
		coordmap.o\
		draw_tab.o\
		draw_lines.o\
		mlx_setup.o\
		read.o\
		list_to_tab.o\
		list_lenght.o\
		error.o\
		main.o

CFLAGS = -Wall -Werror -Wextra

HEADER = ./includes/

all : $(NAME)

$(NAME) :
	@make -C ./libft/
	@make -C ./minilibx_macos/
	@gcc -c $(SRCS) $(FLAGS) -I./includes/
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) ./libft/libft.a ./minilibx_macos/libmlx.a -framework OPENGL -framework Appkit -I ./minilibx_macos -I ./libft/

clean:
	@make clean -C ./libft
	@make clean -C ./minilibx_macos
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C ./libft
	@rm -rf ./fdf

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 19:48:44 by msosnova          #+#    #+#              #
#    Updated: 2021/12/20 18:35:18 by msosnova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJ =	srcs/ft_parsing_data.o\
		srcs/ft_init_map.o\
		srcs/ft_init_data.o\
		srcs/ft_free.o \
		srcs/ft_error.o\
		srcs/ft_map_drawing.o\
		srcs/ft_key_hook.o\
		srcs/ft_move_player.o\
		gnl/get_next_line.o \
		gnl/get_next_line_utils.o\
	


INC = -Iinclude -Ilibft




FLAGS = -g -Wall -Wextra -Werror
CC 	  =	gcc

LIBFT = libft/libft.a

MINILIBX = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	@echo "\033[93m>> so_long obj $@\033[0m"
	$(CC) $(FLAGS) $(INC) -Imlx_linux -o $@ -c $<

all: $(NAME)

$(NAME): mlxlib $(LIBFT) $(OBJ) 
	echo "$(OBJ)"
	@echo "\033[93m>> so_lons compilation\033[0m"
	$(CC) $(FLAGS) $(INC) main.c -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

$(LIBFT):
	@echo "\033[93m>> Libft compilation\033[0m"
	make -C libft

mlxlib:
	@echo "\033[93m>> mlx compilation\033[0m"
	make -C mlx_linux

clean:
	@echo "\033[93m>> Cleaning objects (.obj)\033[0m"
	make $@ -C libft
	rm -f $(OBJ)

fclean: clean
	make $@ -C libft
	rm -f $(NAME)

re:
	make fclean
	make all

bonus: $(NAME)

.PHONY: all, clean, fclean, re, bonus


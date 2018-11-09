# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rejocic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 13:10:40 by rejocic           #+#    #+#              #
#    Updated: 2018/09/10 16:34:49 by rejocic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = @gcc -Wall -Werror -Wextra

FLAGS = -framework OpenGL -framework AppKit

SRC = main.c parser.c imagination.c line.c commands.c

OBJS = $(SRC:.c=.o)

LIB = ./libft/libft.a

MLX = minilibx_macos/libmlx.a

.PHONY: clean, fclean, re, bug

all: $(NAME) $(LIB)

$(NAME): $(OBJS) $(LIB) $(MLX)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLX)

$(OBJS): fdf.h

$(LIB):
	@cd libft && make

$(MLX):
	@cd minilibx_macos && make

bug: $(OBJS) $(LIB) $(MLX)
	$(CC) $(FLAGS) -o bug -g $(SRC) $(LIB) $(MLX)

clean:
	@cd libft && make clean
	@rm -rf bug bug.dSYM
	@rm -f $(OBJS)

fclean: clean
	@cd libft && make fclean
	@rm -rf bug bug.dSYM
	@rm -rf $(NAME)

re: fclean all

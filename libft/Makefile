# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rejocic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:38:21 by rejocic           #+#    #+#              #
#    Updated: 2018/08/24 13:25:01 by rejocic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc

FLAG = -Wall -Werror -Wextra

SRCS = ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_memchr.c \
ft_putnbr_fd.c ft_striter.c ft_strnew.c ft_atoi.c ft_memcmp.c ft_putstr.c \
ft_striteri.c ft_strnstr.c ft_bzero.c ft_memcpy.c ft_putstr_fd.c \
ft_strjoin.c ft_strrchr.c ft_isalnum.c ft_memdel.c ft_strcat.c \
ft_strlcat.c ft_strsplit.c ft_isalpha.c ft_memmove.c ft_strchr.c \
ft_strlen.c ft_strstr.c ft_isascii.c ft_memset.c ft_strclr.c ft_strmap.c \
ft_strsub.c ft_isdigit.c ft_putchar.c ft_strcmp.c ft_strmapi.c \
ft_strtrim.c ft_isprint.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c \
ft_tolower.c ft_itoa.c ft_putendl.c ft_strdel.c ft_strncmp.c ft_toupper.c \
ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_strisalnum.c ft_strisalpha.c ft_strisascii.c ft_strisdigit.c \
ft_strisprint.c get_next_line.c ft_word_count.c

OBJS = $(SRCS:.c=.o)

HEAD = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc libft.a $(OBJS)

.PHONY: all clean fclean re

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

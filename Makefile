# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 11:19:10 by nmeunier          #+#    #+#              #
#    Updated: 2026/02/13 18:59:16 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= libft/ft_putstr_fd.c libft/ft_split.c libft/ft_substr.c \
			libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strjoin.c \
			libft/ft_memcpy.c

SRCS = $(LIBFT) src/main.c src/process.c src/path.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus_re: fclean bonus

.PHONY: all bonus clean fclean re bonus_re


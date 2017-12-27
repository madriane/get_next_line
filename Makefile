# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarandi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 13:34:47 by amarandi          #+#    #+#              #
#    Updated: 2017/12/22 16:44:45 by amarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-g -Wall -Wextra -Werror

all:
	clang $(CFLAGS) -I libft/includes -o main.o -c main.c
	clang $(CFLAGS) -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

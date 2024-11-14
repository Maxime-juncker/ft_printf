# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/14 14:14:10 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft/ -g3
SRCS =  ft_printf.c

OBJ_D = obj/
BIN_D = bin/
OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a

.PHONY: all
all : $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	mv ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ_D)/%.o : %.c libft.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	make clean -C ./libft
	rm -f $(OBJ) $(BOBJ)

.PHONY: fclean
fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

.PHONY: re
re: fclean
	make re -C ./libft
	make all

.PHONY: debug
debug: $(OBJ) $(BOBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) ./libft/*.o main.c -o a.out

.PHONY: valgrind
valgrind: debug
	@valgrind ./a.out



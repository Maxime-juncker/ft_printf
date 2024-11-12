# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/12 12:21:02 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS =  ft_printf.c

OBJ = $(SRCS:.c=.o)
NAME = ft_printf.a

.PHONY: all
all : $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	mv ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c libft.h
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
re: fclean all

.PHONY: debug
debug: $(OBJ) $(BOBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) ./libft/*.o main.c -o a.out



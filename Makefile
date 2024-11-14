# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/14 17:47:10 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ_D = obj/
SRCS_D = src/
INCLUDES_D =	-Iincludes/ \
				-Ilibft/	\


SRCS =  ft_printf.c
OBJ = $(SRCS:.c=.o)

OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES_D)

RM = rm -fr

.PHONY: all
all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	mv ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ) : $(SRCS)
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) re -C ./libft
	$(MAKE) all

.PHONY: debug
debug: $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) ./libft/*.o main.c -o a.out

.PHONY: valgrind
valgrind: debug
	@valgrind --track-origins=yes ./a.out



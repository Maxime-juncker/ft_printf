# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/16 13:19:38 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ_D = obj/
SRCS_D = src/
BIN_D = bin/
INCLUDES_D = -Iincludes/ -Ilibft/includes/

SRCS = ft_printf.c main.c
OBJ = $(SRCS:.c=.o)

OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES_D)

RM = rm -fr

.PHONY: all
all : libft $(NAME)
	cp ./libft/bin/libft.a $(BIN_D)$(NAME)

$(NAME): $(OBJ) | $(BIN_D)
	ar rcs $(BIN_D)$(NAME) $(OBJ)

$(OBJ_D)%.o : $(SRCS_D)%.c | $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(BIN_D)$(NAME)
	$(RM) $(BIN_D)a.out

.PHONY: libft
libft:
	$(MAKE) -C ./libft

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) re -C ./libft
	$(MAKE) all

# Create directories
$(OBJ_D):
	mkdir -p $(OBJ_D)

$(BIN_D):
	mkdir -p $(BIN_D)

# debug targets
.PHONY: debug
debug:
	$(MAKE) so -C ./libft
	$(CC) $(CFLAGS) $(SRCS) ./libft/bin/libft.so -o $(BIN_D)a.out

.PHONY: run
run: debug
	@./$(BIN_D)a.out

.PHONY: valgrind
valgrind: debug
	@valgrind --track-origins=yes ./a.out



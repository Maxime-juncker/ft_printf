# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 12:19:24 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/20 09:26:59 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror $(INCLUDES_D)

SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

OBJ_D = obj/
SRCS_D = src/
BIN_D = bin/
INCLUDES_D = -Iincludes/ -Ilibft/includes/

all: $(NAME)

OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

$(NAME): $(OBJ)
	$(MAKE) -C libft
	mv libft/bin/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ_D)%.o : $(SRCS_D)%.c includes/ft_printf.h | $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
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
debug: $(OBJ) | $(BIN_D)
	$(MAKE) so -C ./libft
	$(CFLAGS) += -g3
	$(CC) $(CFLAGS) -c main.c -o obj/main.o
	$(CC) $(CFLAGS) $(OBJ) obj/main.o ./libft/bin/libft.so -o $(BIN_D)a.out

.PHONY: run
run: debug
	@./$(BIN_D)a.out

.PHONY: valgrind
valgrind: debug
	@valgrind --leak-check=full bin/a.out
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 22:19:13 by gartaud           #+#    #+#              #
#    Updated: 2021/01/15 00:20:34 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OS			= linux
NAME		= miniRT
CC			= gcc
INCLUDES	= includes
CFLAGS		= -Wall -Werror -Wextra -O3 -I$(INCLUDES)
DEPS_DIR	= lib
ifeq ($(OS), linux)
	LFLAGS		= -lft -lmlx -lm
	DEPS		= 	$(DEPS_DIR)/libft/libft.h \
					$(DEPS_DIR)/mlx_linux/mlx.h
	MLX_DIR		=	$(DEPS_DIR)/mlx_linux
else
	LFLAGS		= -Llib/libft -lft -Llib/mlx_macos -lmlx -lm
	DEPS		= 	$(DEPS_DIR)/libft/libft.h \
					$(DEPS_DIR)/mlx_macos/mlx.h
	MLX_DIR		=	$(DEPS_DIR)/mlx_macos
endif
LIBFT		= libft.a
LIBFT_DIR	= $(DEPS_DIR)/libft
MLX			= libmlx.a
FILES		= miniRT.c
OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) -L$(DEPS_DIR) $< -o $@ $(LFLAGS)

$(MLX):
	make -sC $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) $(DEPS_DIR)

$(LIBFT):
	make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(DEPS_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -sC $(LIBFT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(DEPS_DIR)/$(LIBFT) $(DEPS_DIR)/$(MLX)
	make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re

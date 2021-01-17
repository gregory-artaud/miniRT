# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 22:19:13 by gartaud           #+#    #+#              #
#    Updated: 2021/01/17 13:18:41 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OS			= linux
NAME		= miniRT
CC			= gcc
INCLUDES	= includes
CFLAGS		= -Wall -Werror -Wextra -O3
DEPS_DIR	= lib
ifeq ($(OS), linux)
	LFLAGS		= -L$(DEPS_DIR) -lft -lmlx -lXext -lX11 -lm -lbsd
	MLX_DIR		=	$(DEPS_DIR)/minilibx-linux-master
	DEPS		= 	$(DEPS_DIR)/libft/libft.h \
					$(MLX_DIR)/mlx.h
else
	LFLAGS		= -Llib/libft -lft -Llib/mlx_macos -lmlx -lm
	MLX_DIR		=	$(DEPS_DIR)/mlx_macos
	DEPS		= 	$(DEPS_DIR)/libft/libft.h \
					$(DEPS_DIR)/mlx_macos/mlx.h
endif
LIBFT		= libft.a
LIBFT_DIR	= $(DEPS_DIR)/libft
MLX			= *.a
FILES		= miniRT.c
OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $< lib/lib*.a $(LFLAGS) -o $@

$(MLX):
	make -sC $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) $(DEPS_DIR)

$(LIBFT):
	make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(DEPS_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -sC $(LIBFT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(DEPS_DIR)/$(LIBFT) $(DEPS_DIR)/$(MLX)
	make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re

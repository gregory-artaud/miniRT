# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 22:19:13 by gartaud           #+#    #+#              #
#    Updated: 2021/01/17 19:36:23 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OS			= linux
NAME		= miniRT
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3 -I $(DEPS_DIR)
LIB_DIR	= lib
ifeq ($(OS), linux)
	LFLAGS		= -L$(LIB_DIR) -lft -lmlx -lXext -lX11 -lm -lbsd
	MLX_DIR		=	$(LIB_DIR)/mlx_linux
else
	LFLAGS		= -Llib/libft -lft -Llib/mlx_macos -lmlx -lm
	MLX_DIR		=	$(LIB_DIR)/mlx_macos
endif
DEPS_DIR	= includes
DEPS		= 	$(addprefix $(DEPS_DIR)/, \
					libft/libft.h \
					mlx.h \
					miniRT.h)
LIBFT		= libft.a
LIBFT_DIR	= $(LIB_DIR)/libft
MLX			= *.a
SRC_DIR		= src/
FILES		= 	miniRT.c \
				src/exit_prog.c \
				src/init.c \
				src/keyboard_hook.c
OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) lib/lib*.a $(LFLAGS) -o $@

$(MLX):
	make -sC $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) $(LIB_DIR)

$(LIBFT):
	make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(LIB_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -sC $(LIBFT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(MLX)
	make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 22:19:13 by gartaud           #+#    #+#              #
#    Updated: 2021/01/22 11:23:19 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OS			= linux
NAME		= miniRT
NORME		= ~/.norminette/norminette.rb
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3 -I $(DEPS_DIR)
LIB_DIR	= lib
LIBFT_DIR	= $(LIB_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a
ifeq ($(OS), linux)
	MLX_DIR		= $(LIB_DIR)/mlx_linux
	LFLAGS		= -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lm -lbsd
	NORME		= ~/.norminette/norminette.rb
else
	LFLAGS		= -L$(LIB_DIR) -lft -lmlx  -lm -framework OpenGL -framework AppKit
	MLX_DIR		=	$(LIB_DIR)/mlx_macos
	NORME		= norminette
endif
DEPS_DIR	= includes
DEPS		= 	$(addprefix $(DEPS_DIR)/, \
					libft/libft.h \
					mlx.h \
					scene.h \
					mini_rt.h)
MLX			= $(MLX_DIR)/libmlx.a
SRC_DIR		= src/
FILES		= 	mini_rt.c \
				src/scene/scene.c \
				src/exit_prog.c \
				src/init.c \
				src/keyboard_hook.c \
				src/render.c
OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $? $(LFLAGS) -o $@

$(MLX):
	make -sC $(MLX_DIR)

$(LIBFT):
	make -sC $(LIBFT_DIR)

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

norme:
	$(NORME) mini_rt.c src/ includes/

.PHONY: clean fclean all re

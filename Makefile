# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 22:19:13 by gartaud           #+#    #+#              #
#    Updated: 2021/02/23 18:26:35 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OS			= linux
NAME		= miniRT
NORME		= ~/.norminette/norminette.rb
DEPS_DIR	= includes
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
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3 \
				-I ./$(DEPS_DIR) -I ./$(LIBFT_DIR) -I ./$(MLX_DIR)
DEPS		= 	$(addprefix $(DEPS_DIR)/, \
					bmp.h \
					scene.h \
					mini_rt.h \
					objects.h)
DEPS		+= $(addprefix $(LIB_DIR)/, \
					libft/libft.h \
					mlx_linux/mlx.h)

MLX			= $(MLX_DIR)/libmlx.a
SRC_DIR		= src/
FILES		= 	mini_rt.c \
				src/bmp/init_bmp.c \
				src/bmp/init_bmp_utils.c \
				src/bmp/bmp_pixel_put.c \
				src/bmp/bmp_export.c \
				src/objects/matrix.c \
				src/objects/init_vect.c \
				src/objects/init_sp.c \
				src/objects/init_pl.c \
				src/objects/init_object.c \
				src/objects/init_c.c \
				src/objects/init_l.c \
				src/objects/init_ray.c \
				src/objects/obj_utils.c \
				src/objects/v_utils.c \
				src/objects/v_utils_2.c \
				src/objects/v_utils_3.c \
				src/objects/l_utils.c \
				src/scene/scene.c \
				src/scene/scene_utils.c \
				src/exit_prog.c \
				src/parsing.c \
				src/ray_tracing.c \
				src/ray_tracing_utils.c \
				src/print.c \
				src/init.c \
				src/keyboard_hook.c \
				src/next_cam.c \
				src/render.c
OBJ 		= $(FILES:%.c=%.o)
DEFAULT		= default.rt
IMG			= image.bmp
VFLAGS		= --leak-check=full --track-origins=yes

all: $(LIBFT) $(MLX) $(NAME)

run: clean all
	./$(NAME) $(DEFAULT)

save: clean all
	./$(NAME) $(DEFAULT) --save

mlfs: clean all
	valgrind $(VFLAGS) ./$(NAME) $(DEFAULT) --save

ml: clean all
	valgrind ./$(NAME) $(DEFAULT)

mlf: clean all
	valgrind $(VFLAGS) ./$(NAME) $(DEFAULT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MLX) $(LFLAGS) -o $@

$(MLX):
	make -sC $(MLX_DIR)

$(LIBFT):
	make -sC $(LIBFT_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(IMG)
	make -sC $(LIBFT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(MLX)
	make -sC $(LIBFT_DIR) fclean

re: fclean all

norme:
	$(NORME) mini_rt.c src/ includes/

.PHONY: clean fclean all re

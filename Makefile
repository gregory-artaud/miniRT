# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 22:19:13 by gartaud           #+#    #+#              #
#    Updated: 2021/04/02 07:49:02 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OS			= macos
NAME		= miniRT
DEPS_DIR	= includes
LIB_DIR		= lib
LIBFT_DIR	= $(LIB_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a
ifeq ($(OS), linux)
	MLX_DIR		= $(LIB_DIR)/mlx_linux
	LFLAGS		= -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lm -lbsd - lpthread
	NORME		= ~/.local/bin/norminette
	MLX			= $(MLX_DIR)/libmlx.a
else
	LFLAGS		= -L$(LIB_DIR) -lpthread -lm -framework OpenGL -framework AppKit
	MLX_DIR		=	$(LIB_DIR)/mlx_macos
	NORME		= norminette
	MLX			= $(MLX_DIR)/libmlx.dylib
endif
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3 \
				-I ./$(DEPS_DIR) -I ./$(LIBFT_DIR) -I ./$(MLX_DIR)
DEPS		= includes/bmp.h \
				includes/mini_rt.h \
				includes/objects.h \
				includes/objects_def.h \
				includes/parser_def.h \
				includes/scene.h \
				lib/libft/libft.h \
				$(MLX_DIR)/mlx.h
FILES		= mini_rt.c \
				src/bmp/bmp_export.c \
				src/bmp/bmp_pixel_put.c \
				src/bmp/init_bmp.c \
				src/bmp/init_bmp_utils.c \
				src/hooks.c \
				src/init_data.c \
				src/init_mlx.c \
				src/objects/algebra/matrix.c \
				src/objects/algebra/ray.c \
				src/objects/algebra/vector.c \
				src/objects/algebra/vector_utils.c \
				src/objects/algebra/vector_utils_2.c \
				src/objects/algebra/vector_utils_3.c \
				src/objects/algebra/vector_utils_4.c \
				src/objects/object.c \
				src/objects/object_utils.c \
				src/objects/shapes/circle.c \
				src/objects/shapes/cylinder.c \
				src/objects/shapes/cylinder_utils.c \
				src/objects/shapes/plane.c \
				src/objects/shapes/sphere.c \
				src/objects/shapes/square.c \
				src/objects/shapes/triangle.c \
				src/objects/shapes/triangle_utils.c \
				src/objects/sight/camera.c \
				src/objects/sight/light.c \
				src/objects/sight/light_utils.c \
				src/ray_tracing.c \
				src/render.c \
				src/scene/next_cam.c \
				src/scene/parsing/add_camera.c \
				src/scene/parsing/add_circle.c \
				src/scene/parsing/add_cylinder.c \
				src/scene/parsing/add_light.c \
				src/scene/parsing/add_plane.c \
				src/scene/parsing/add_sphere.c \
				src/scene/parsing/add_square.c \
				src/scene/parsing/add_triangle.c \
				src/scene/parsing/set_ambiant.c \
				src/scene/parsing/set_resolution.c \
				src/scene/parsing.c \
				src/scene/parsing_utils.c \
				src/scene/scene.c \
				src/ssaa.c \
				src/ssaa_utils.c
OBJ 		= $(FILES:%.c=%.o)
DEFAULT		= scenes/default.rt
IMG			= image.bmp

all:
	$(MAKE) BONUS=0 $(LIBFT) $(MLX) $(NAME)

bonus:
	$(MAKE) BONUS=1 $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MLX) $(LFLAGS) -o $@

$(MLX):
	make -sC $(MLX_DIR)
	cp $@ .

$(LIBFT):
	make -sC $(LIBFT_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -D BONUS=$(BONUS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(IMG)
	make -sC $(LIBFT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) libmlx.dylib $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(MLX)
	make -sC $(LIBFT_DIR) fclean

re: fclean all

norme:
	$(NORME) mini_rt.c src/ includes/

.PHONY: clean fclean all re

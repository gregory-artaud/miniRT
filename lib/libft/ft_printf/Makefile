# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 15:38:17 by gartaud           #+#    #+#              #
#    Updated: 2021/01/14 18:08:42 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3
FILES		= ft_printf.c \
				src/fill.c \
				src/convert.c \
				src/t_print.c \
				src/spclen.c \
				src/init_spc.c \
				src/process_spc.c \
				src/get_flag.c \
				src/apply_flags_nb.c \
				src/apply_c.c \
				src/apply_d.c \
				src/apply_p.c \
				src/apply_u.c \
				src/apply_x.c \
				src/apply_big_x.c \
				src/apply_s.c \
				src/apply_percent.c
OBJ			= $(FILES:%.c=%.o)
HEADER		= includes
LIBFT		= ..
#NORME		= ~/.norminette/norminette.rb
NORME		= norminette

all: $(NAME)

$(NAME): $(OBJ)
	make -sC $(LIBFT) libft.a
	@cp ../libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	$(NORME) includes/ft_printf.h ft_printf.c src/*.c libft/*.c libft/*.h

.PHONY: clean fclean all re

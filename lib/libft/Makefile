# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/28 13:46:16 by gartaud           #+#    #+#              #
#    Updated: 2021/03/07 14:12:51 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SHARED		= libft.so
BUFFER_SIZE	= 256
CFLAGS		= -Wall -Werror -Wextra
FT_PRINTF	= ft_printf
CC			= gcc
DEPS		= 	libft.h \
				gnl/get_next_line.h \
				ft_printf/includes/ft_printf.h
FILES		=	ft_memset.c \
				ft_memmove.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memcmp.c \
				ft_memchr.c \
				ft_bzero.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_strnstr.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_cs_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strndup.c \
				ft_abs.c \
				ft_strinsert.c \
				ft_strmcat.c \
				ft_itoa_base.c \
				ft_strpad.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_free_strarray.c \
				ft_arrlen.c \
				ft_atof.c \
				ft_isspace.c \
				ft_is_int.c \
				ft_is_double.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c
OBJ			= $(FILES:%.c=%.o)

all: $(FT_PRINTF)

$(FT_PRINTF): $(OBJ)
	make -sC $@
	cp ft_printf/libftprintf.a ./$(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	make -sC $(FT_PRINTF) clean
	rm -f $(OBJ)

fclean: clean
	make -sC $(FT_PRINTF) fclean
	rm -f $(NAME)
	rm -f $(SHARED)

re: fclean all

.PHONY: clean fclean all re

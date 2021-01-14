/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:37:54 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/14 18:12:34 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define CONVERSION_NB 8
# include "../../libft.h"

typedef struct	s_print
{
	char		*format;
	char		*out;
	int			min_width;
	int			precision;
	char		type;
	va_list		*args;
}				t_print;

int				ft_printf(const char *s, ...);
int				fill(t_print *p, int *i);
int				convert(t_print *p, int *i);
t_print			*pinit(va_list *args, char *format);
void			pfree(t_print *p);
int				spclen(char *s);
int				isflag(char c);
int				isconvert(char c);
void			reset_spc(t_print *p);
void			init_spc(t_print *p, int head);
int				process_spc(char **dest, t_print *p, int spc_i);
char			get_flag(t_print *p, int spc_i);
void			insert_minus(char **dest);
void			apply_flags_nb(char **dest, t_print *p, int spc_i, int is_neg);
int				apply_c(char **dest, t_print *p, int spc_i);
int				apply_s(char **dest, t_print *p, int spc_i);
int				apply_p(char **dest, t_print *p, int spc_i);
int				apply_d(char **dest, t_print *p, int spc_i);
int				apply_u(char **dest, t_print *p, int spc_i);
int				apply_x(char **dest, t_print *p, int spc_i);
int				apply_big_x(char **dest, t_print *p, int spc_i);
int				apply_percent(char **dest, t_print *p, int spc_i);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:39:51 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/23 19:17:46 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <fcntl.h>
# include "scene.h"
# define SAVE_FILE "image.bmp"
# define ACCESS_RIGHTS 0777

typedef	struct	s_bfh
{
	char		*type;
	int			size;
	int			reserved;
	int			offset;
}				t_bfh;
typedef	struct	s_bih
{
	int			size;
	int			w;
	int			h;
	short		planes;
	short		bit_count;
}				t_bih;
typedef	struct	s_bmp
{
	t_bfh		*bfh;
	t_bih		*bih;
	t_list		*pxl;
}				t_bmp;

t_bmp			*init_bmp(t_scene *scene);
void			free_bmp(t_bmp *bmp);
t_bfh			*init_bfh(t_scene *scene);
void			free_bfh(t_bfh *bfh);
t_bih			*init_bih(t_scene *scene);
void			free_bih(t_bih *bih);
void			free_pxl(void *pxl);
int				save_img(t_bmp *bmp);
void			bmp_pixel_put(t_bmp *bmp, int c);
int				export(int fd, t_bmp *bmp);
#endif

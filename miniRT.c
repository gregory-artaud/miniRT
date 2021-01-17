/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 13:07:04 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx_macos/mlx.h"
#include "mlx.h"
#include "libft.h"

int main()
{
	void	*mlx;
	//void	*mlx_win;
	//int		w_h;
	//int		w_w;	

	//w_w = 1920;
	//w_h = 1080;
	if (!(mlx = mlx_init()))
		return (EXIT_FAILURE);
	ft_printf("%p\n", mlx);
	/*
	mlx_win = mlx_new_window(mlx, w_w, w_h, "Hello world !");

	for (int i = 0; i < w_w; i++)
		for (int j = 0; j < w_h; j++)
			mlx_pixel_put(mlx, mlx_win, i, j, i * j);
	mlx_loop(mlx);
	*/
	return (EXIT_SUCCESS);
}

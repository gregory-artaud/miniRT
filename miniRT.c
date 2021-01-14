/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/15 00:08:29 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx_macos/mlx.h"
#include "mlx.h"
#include "libft.h"

int main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world !");

	for (int i = 0; i < 1920; i++)
		for (int j = 0; j < 1080; j++)
			mlx_pixel_put(mlx, mlx_win, i, j, i * j);
	mlx_loop(mlx);
	return (0);
}

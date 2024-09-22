/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:33:18 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/21 21:08:56 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_structs.h"
#include "mlx.h"

#ifndef WIN_W
# define WIN_W 500
#endif

#ifndef WIN_H
# define WIN_H 500
#endif

void	init_mlx(t_mlxs *mlxs)
{
	mlxs->mlx = mlx_init();
	mlxs->mlx_win = mlx_new_window(mlxs->mlx, WIN_W,
			WIN_H, "miniRT");
	mlxs->img.img = mlx_new_image(mlxs->mlx, WIN_W, WIN_H);
	mlxs->img.addr = mlx_get_data_addr(mlxs->img.img,
			&mlxs->img.bits_per_pixel, &mlxs->img.line_length,
			&mlxs->img.endian);
}

void	set_img_pixel_color(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = img.addr + (y * img.line_length + \
		x * (img.bits_per_pixel / 8));
		if (img.endian)
		{
			color = ((color >> 24) & 0xff)
				| ((color >> 8) & 0xff00)
				| ((color << 8) & 0xff0000)
				| ((color << 24) & 0xff000000);
		}
		*(unsigned int *)dst = color;
	}
}

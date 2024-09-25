/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:40:25 by jyap              #+#    #+#             */
/*   Updated: 2024/09/25 21:43:42 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "color.h"

t_ray	init_ray(double x, double y, t_mlxs *mlxs)
{
	int		max;
	t_ray	ray;

	max = WIN_H;
	if (WIN_W > WIN_H)
		max = WIN_W;
	ray.dir = add(mult(mlxs->sc->cam.u, x - WIN_W * 0.5),
			mult(mlxs->sc->cam.v, y - WIN_H * 0.5));
	ray.dir = add(ray.dir,
			mult(mlxs->sc->cam.norm,
				max / (2 * tan((mlxs->sc->cam.fov_deg * 0.5) * M_PI / 180.0))));
	ray.pos = mlxs->sc->cam.pos;
	return (ray);
}

t_color	get_pixel_color(t_inter *inter)
{
	t_color		background;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;

	background = color(0, 0, 0);
	if (inter->type == PLANE)
	{
		pl = (t_plane *)inter->obj_ptr;
		inter->color = pl->color;
	}
	else if (inter->type == SPHERE)
	{
		sp = (t_sphere *)inter->obj_ptr;
		inter->color = sp->color;
	}
	else if (inter->type == CYLINDER)
	{
		cy = (t_cylinder *)inter->obj_ptr;
		inter->color = cy->color;
	}
	else
		inter->color = background;
	return (inter->color);
}

void	launch_rays_from_camera(t_mlxs *mlxs)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	pix_color;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			ray = init_ray(x, y, mlxs);
			closest_inter(mlxs, &ray);
			if (ray.inter.i == -1)
				pix_color = color(0, 0, 0);
			else
				pix_color = add_color(ray.inter.color,
						color_ambient(mlxs), color_diffuse(mlxs, &(ray.inter)));
			set_img_pixel_color(mlxs->img, x, y, get_trgb(pix_color, 0));
			if (ray.inter.i == -1)
				mlxs->arr_obj_ptrs[(WIN_W * y) + x] = NULL;
			else
				mlxs->arr_obj_ptrs[(WIN_W * y) + x] = ray.inter.obj_ptr;
		}
	}
}

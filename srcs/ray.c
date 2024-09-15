/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:40:25 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 18:03:51 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

t_ray	init_ray(double x, double y, t_mlxs *mlxs)
{
	t_vect	v;
	int		max;
	t_ray	ray;

	max = WIN_H;
	if (WIN_W > WIN_H)
		max = WIN_W;
	v.x = x - WIN_W * 0.5;
	v.y = y - WIN_H * 0.5;
	v.z = max / (2 * tan((mlxs->sc->cam.fov_deg * 0.5) * M_PI / 180.0));
	ray.dir = normalize(v);
	ray.pos = mlxs->sc->cam.pos;
	return (ray);
}

t_color	get_pixel_color(t_inter *inter)
{
	t_color	background;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;

	background.r = 0;
	background.g = 0;
	background.b = 0;
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
	double	x;
	double	y;
	t_ray	ray;
	t_color	color;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			ray = init_ray(x, y, mlxs);
			closest_inter(mlxs, &ray);
			color = get_pixel_color(ray.inter);
			set_pixel_color(mlxs->img, x, y, get_trgb(color, 0));
		}
	}
}
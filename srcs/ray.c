/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:40:25 by jyap              #+#    #+#             */
/*   Updated: 2024/09/22 00:48:25 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "color.h"

// Step 1: Compute the rotation axis (cross product of (0, 0, 1) and target)
// Step 2: Normalize the rotation axis
// Step 3: Compute the angle (dot product of (0, 0, 1) and target)
// Step 4: Compute cross product of rotation axis and p
// Step 5: Compute dot product of rotation axis and p
// Step 6: Apply Rodrigues' rotation formula
t_vect	rotate_vector(t_vect p, t_vect target)
{
	t_vect	rotation_axis;
	double	sin_theta;
	t_vect	cross;
	double	dot;

	rotation_axis = normalize(vect(-target.y, target.x, 0));
	sin_theta = sqrt(1 - target.z * target.z);
	cross = cross_product(rotation_axis, p);
	dot = dot_product(rotation_axis, p);
	return (vect(p.x * target.z + cross.x * sin_theta
			+ rotation_axis.x * dot * (1 - target.z),
			p.y * target.z + cross.y * sin_theta
			+ rotation_axis.y * dot * (1 - target.z),
			p.z * target.z + cross.z * sin_theta
			+ rotation_axis.z * dot * (1 - target.z)));
}

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
	v = normalize(v);
	if (vect_is_equal(vect(0, 0, 1), mlxs->sc->cam.norm))
		ray.dir = v;
	else if (vect_is_equal(vect(0, 0, -1), mlxs->sc->cam.norm))
		ray.dir = vect(-v.x, -v.y, -v.z);
	else
		ray.dir = rotate_vector(v, mlxs->sc->cam.norm);
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
		}
	}
}

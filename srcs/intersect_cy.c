/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:29:35 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:52:56 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool	is_intersection_valid(t_ray *ray, t_cylinder *cy, double t)
{
	t_vect	p_intersection;
	t_vect	d;
	double	m;

	if (t < 0)
		return (false);
	p_intersection = add(ray->pos, mult(ray->dir, t));
	d = sub(p_intersection, cy->pos);
	m = dot_product(d, cy->norm_axis);
	return (m >= 0 && m <= cy->height);
}

t_vect	cylinder_normal(t_vect P, t_cylinder *cylinder)
{
	t_vect	cp;
	t_vect	norm_dir;
	double	m;

	cp = sub(P, cylinder->pos);
	m = dot_product(cp, cylinder->norm_axis);
	norm_dir = sub(cp, mult(cylinder->norm_axis, m));
	return (normalize(norm_dir));
}

int	quad_cylinder(t_ray *ray, t_inter *inter, t_cylinder *cylinder, t_vect X)
{
	double	quad[4];
	double	dist[2];

	quad[0] = dot_product(ray->dir, ray->dir) \
	- pow(dot_product(ray->dir, cylinder->norm_axis), 2);
	quad[1] = 2 * (dot_product(ray->dir, X) - \
	(dot_product(ray->dir, cylinder->norm_axis) \
	* dot_product(X, cylinder->norm_axis)));
	quad[2] = dot_product(X, X) - \
	pow(dot_product(X, cylinder->norm_axis), 2) - pow(cylinder->dia / 2, 2);
	quad[3] = quad[1] * quad[1] - 4 * quad[0] * quad[2];
	if (quad[3] < 0)
		return (inter->dist = INFINITY, 0);
	dist[0] = (-quad[1] - sqrt(quad[3])) / (2 * quad[0]);
	dist[1] = (-quad[1] + sqrt(quad[3])) / (2 * quad[0]);
	if (!is_intersection_valid(ray, cylinder, dist[0]))
		dist[0] = dist[1];
	if (!is_intersection_valid(ray, cylinder, dist[0]))
		return (inter->dist = INFINITY, 0);
	inter->dist = dist[0];
	return (1);
}

t_inter	intersect_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_inter	inter;
	t_vect	x;

	inter.type = CYLINDER;
	inter.obj_ptr = cylinder;
	x = vect(ray->pos.x - cylinder->pos.x, ray->pos.y - \
	cylinder->pos.y, ray->pos.z - cylinder->pos.z);
	if (!quad_cylinder(ray, &inter, cylinder, x))
		return (inter);
	inter.point = add(ray->pos, mult(ray->dir, inter.dist));
	inter.normal = cylinder_normal(inter.point, cylinder);
	return (inter);
}

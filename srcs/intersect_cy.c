/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:29:35 by jyap              #+#    #+#             */
/*   Updated: 2024/09/25 22:13:09 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool	is_intersection_valid(t_ray *ray, t_cylinder *cy, double t)
{
	t_vect	p_intersection;
	t_vect	d;
	double	m;

	if (t < 1e-4)
		return (false);
	p_intersection = add(ray->pos, mult(ray->dir, t));
	d = sub(p_intersection, cy->pos);
	m = dot_product(d, cy->norm_axis);
	return (m >= -cy->height / 2 && m <= cy->height / 2);
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
	if (quad[3] < 1e-4)
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

double	intersect_cylinder_cap(t_ray *ray, t_cylinder *cylinder, int sign)
{
	t_vect	cap_center;
	t_vect	vect;
	double	denom;
	double	t;

	cap_center = add(cylinder->pos,
			mult(cylinder->norm_axis, sign * cylinder->height / 2));
	denom = dot_product(ray->dir, cylinder->norm_axis);
	if (fabs(denom) < 1e-4)
		return (INFINITY);
	t = dot_product(sub(cap_center, ray->pos), cylinder->norm_axis) / denom;
	if (t < 1e-4)
		return (INFINITY);
	vect = sub(add(ray->pos, mult(ray->dir, t)), cap_center);
	if (dot_product(vect, vect) <= (cylinder->dia / 2) * (cylinder->dia / 2))
		return (t);
	return (INFINITY);
}

t_inter	intersect_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_inter	inter;
	t_vect	x;
	double	dist[3];

	inter.type = CYLINDER;
	inter.obj_ptr = cylinder;
	x = sub(ray->pos, cylinder->pos);
	if (!quad_cylinder(ray, &inter, cylinder, x))
		dist[0] = INFINITY;
	else
		dist[0] = inter.dist;
	dist[1] = intersect_cylinder_cap(ray, cylinder, -1);
	dist[2] = intersect_cylinder_cap(ray, cylinder, 1);
	inter.dist = fmin(dist[0], fmin(dist[1], dist[2]));
	if (inter.dist == INFINITY)
		return (inter);
	inter.point = add(ray->pos, mult(ray->dir, inter.dist));
	if (inter.dist == dist[0])
		inter.normal = cylinder_normal(inter.point, cylinder);
	else
		inter.normal = cylinder->norm_axis;
	if (inter.dist == dist[1])
		inter.normal = mult(inter.normal, -1);
	inter.color = cylinder->color;
	return (inter);
}

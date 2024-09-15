/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:32:07 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 17:08:23 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

double	solve_quadratic(double a, double b, double c)
{
	double	d;
	double	t1;
	double	t2;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if (t1 < 0 && t2 < 0)
		return (-1);
	else if (t1 >= 0)
		return (t1);
	else
		return (t2);
}

double	dot_product(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	distance(t_vect v1, t_vect v2)
{
	double	dx;
	double	dy;
	double	dz;

	dx = v2.x - v1.x;
	dy = v2.y - v1.y;
	dz = v2.z - v1.z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

t_vect	add(t_vect v1, t_vect v2)
{
	t_vect	vect;

	vect.x = v1.x + v2.x;
	vect.y = v1.y + v2.y;
	vect.z = v1.z + v2.z;
	return (vect);
}

t_vect	sub(t_vect v1, t_vect v2)
{
	t_vect	vect;

	vect.x = v1.x - v2.x;
	vect.y = v1.y - v2.y;
	vect.z = v1.z - v2.z;
	return (vect);
}

t_vect	mult(t_vect v, double scale)
{
	t_vect	vect;

	vect.x = v.x * scale;
	vect.y = v.y * scale;
	vect.z = v.z * scale;
	return (vect);
}

t_vect	normalize(t_vect v)
{
	double	length;
	t_vect	v1;

	length = distance(vect(0, 0, 0), v);
	v1.x = v.x / length;
	v1.y = v.y /length;
	v1.z = v.z / length;
	return (v1);
}
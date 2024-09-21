/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:36 by jyap              #+#    #+#             */
/*   Updated: 2024/09/22 03:39:19 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

double	solve_quadratic(double a, double b, double c)
{
	double	d;
	double	t1;
	double	t2;

	d = b * b - 4 * a * c;
	if (d < 1e-4)
		return (-1);
	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if (t1 < 1e-4 && t2 < 1e-4)
		return (-1);
	else if (t1 >= 1e-4)
		return (t1);
	else
		return (t2);
}

double	dot_product(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect	cross_product(t_vect v1, t_vect v2)
{
	t_vect	ret;

	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return (ret);
}

// Apply rotation to p such that the z-axis in p's coordinate system coincides
// with target.
// target must be a unit vector.
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

	if (fabs(target.z - 1) < 1e-4)
		return (p);
	if (fabs(target.z + 1) < 1e-4)
		return (mult(target, -1));
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

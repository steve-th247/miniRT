/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:36 by jyap              #+#    #+#             */
/*   Updated: 2024/09/20 15:17:14 by jyap             ###   ########.fr       */
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

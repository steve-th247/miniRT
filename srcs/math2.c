/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:36 by jyap              #+#    #+#             */
/*   Updated: 2024/09/20 10:07:34 by tjien-ji         ###   ########.fr       */
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

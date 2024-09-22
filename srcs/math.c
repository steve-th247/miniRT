/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:36 by jyap              #+#    #+#             */
/*   Updated: 2024/09/22 20:13:50 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:09:14 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 01:53:41 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_H
# define VECT_H

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}	t_vect;

t_vect	vect(double x, double y, double z);
t_vect	*create_vect(double x, double y, double z);
void	delete_vect(t_vect *ptr_vect);
char	vect_is_equal(t_vect v1, t_vect v2);

double	distance(t_vect v1, t_vect v2);
t_vect	mult(t_vect v, double scale);
t_vect	sub(t_vect v1, t_vect v2);
t_vect	add(t_vect v1, t_vect v2);
t_vect	normalize(t_vect v);

double	dot_product(t_vect v1, t_vect v2);
t_vect	cross_product(t_vect v1, t_vect v2);
t_vect	rotate_around_axis(t_vect dir, t_vect axis, double angle);
t_vect	rotate_vector(t_vect p, t_vect target);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:57:35 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 17:31:42 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vect.h"
# include "color.h"

typedef struct s_sphere	t_sphere;

struct s_sphere
{
	void		(*translate)(t_sphere *, t_vect);
	void		(*rotate)(t_sphere *, t_vect);
	void		(*resize_1)(t_sphere *, double);
	void		(*resize_2)(t_sphere *, double);
	int			i;
	t_vect		pos;
	t_color		color;
	double		dia;
};

t_sphere	sphere(t_vect pos, double dia, t_color color);
t_sphere	*create_sphere(t_vect pos, double dia, t_color color);
void		delete_sphere(t_sphere *ptr_sphere);
void		translate_sphere(t_sphere *sphere, t_vect vector);
void		resize_sphere(t_sphere *sphere, double delta);

#endif

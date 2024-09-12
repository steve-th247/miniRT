/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:57:35 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/09 23:07:34 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vect.h"
# include "color.h"

typedef struct s_sphere
{
	t_vect		pos;
	t_color		color;
	double		dia;
}	t_sphere;

t_sphere	sphere(t_vect pos, double dia, t_color color);
t_sphere	*create_sphere(t_vect pos, double dia, t_color color);
void		delete_sphere(t_sphere *ptr_sphere);

#endif

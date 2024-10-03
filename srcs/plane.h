/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:09:34 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 23:12:48 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vect.h"
# include "color.h"

typedef struct s_plane	t_plane;

struct s_plane
{
	void	(*translate)(t_plane *, t_vect);
	void	(*rotate)(t_plane *, t_vect, double);
	void	(*resize_1)(t_plane *, double);
	void	(*resize_2)(t_plane *, double);
	int		i;
	t_vect	pos;
	t_vect	norm;
	t_color	color;
};

t_plane	plane(t_vect pos, t_vect norm, t_color color);
t_plane	*create_plane(t_vect pos, t_vect norm, t_color color);
void	delete_plane(t_plane *ptr_plane);
void	translate_plane(t_plane *plane, t_vect vector);
void	rotate_plane(t_plane *plane, t_vect axis, double deg);

#endif

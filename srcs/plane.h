/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:09:34 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/22 18:51:54 by tjien-ji         ###   ########.fr       */
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
	void	(*rotate)(t_plane *, t_vect);
	void	(*resize_1)(t_plane *, double);
	void	(*resize_2)(t_plane *, double);
	t_vect	pos;
	t_vect	norm;
	t_color	color;
};

t_plane	plane(t_vect pos, t_vect norm, t_color color);
t_plane	*create_plane(t_vect pos, t_vect norm, t_color color);
void	delete_plane(t_plane *ptr_plane);
void	translate_plane(t_plane *plane, t_vect vector);
void	rotate_plane(t_plane *plane, t_vect target_z);

#endif

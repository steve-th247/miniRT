/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:01:41 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 17:49:46 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "plane.h"
#include "vect.h"
#include "obj.h"

t_plane	plane(t_vect pos, t_vect norm, t_color color)
{
	t_plane	plane;

	plane.i = PLANE;
	plane.pos = pos;
	plane.norm = norm;
	plane.color = color;
	plane.translate = translate_plane;
	plane.rotate = rotate_plane;
	plane.resize_1 = NULL;
	plane.resize_2 = NULL;
	return (plane);
}

t_plane	*create_plane(t_vect pos, t_vect norm, t_color color)
{
	t_plane			*ptr_new_plane;

	ptr_new_plane = malloc(sizeof(*ptr_new_plane));
	if (!ptr_new_plane)
	{
		perror("Could not allocate memory");
		exit(errno);
	}
	*ptr_new_plane = plane(pos, norm, color);
	return (ptr_new_plane);
}

void	delete_plane(t_plane *ptr_plane)
{
	free(ptr_plane);
}

void	translate_plane(t_plane *plane, t_vect vector)
{
	plane->pos = add(plane->pos, vector);
}

void	rotate_plane(t_plane *plane, t_vect target_z)
{
	plane->norm = rotate_vector(plane->norm, target_z);
	plane->pos = rotate_vector(plane->pos, target_z);
}

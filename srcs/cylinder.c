/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:30:41 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/22 21:56:54 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "cylinder.h"

t_cylinder	cylinder(t_vect pos, t_vect norm, t_color color,
				double size_info[2])
{
	t_cylinder	cylinder;

	cylinder.pos = pos;
	cylinder.norm_axis = norm;
	cylinder.color = color;
	cylinder.dia = size_info[0];
	cylinder.height = size_info[1];
	cylinder.translate = translate_cylinder;
	cylinder.rotate = rotate_cylinder;
	cylinder.resize_1 = resize_cylinder_1;
	cylinder.resize_2 = resize_cylinder_2;
	return (cylinder);
}

t_cylinder	*create_cylinder(t_vect pos, t_vect norm_axis, t_color color,
				double size_info[2])
{
	t_cylinder			*ptr_new_cylinder;

	ptr_new_cylinder = malloc(sizeof(*ptr_new_cylinder));
	if (!ptr_new_cylinder)
	{
		perror("Could not allocate memory");
		exit(errno);
	}
	*ptr_new_cylinder = cylinder(pos, norm_axis, color, size_info);
	return (ptr_new_cylinder);
}

void	delete_cylinder(t_cylinder *ptr_cylinder)
{
	free(ptr_cylinder);
}

void	translate_cylinder(t_cylinder *cyl, t_vect vector)
{
	cyl->pos = add(cyl->pos, vector);
}

void	rotate_cylinder(t_cylinder *cyl, t_vect target_z)
{
	cyl->norm_axis = rotate_vector(cyl->norm_axis, target_z);
}

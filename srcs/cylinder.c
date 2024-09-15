/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:30:41 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/14 18:17:31 by jyap             ###   ########.fr       */
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

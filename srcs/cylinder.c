/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:30:41 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/09 23:55:38 by tjien-ji         ###   ########.fr       */
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
	cylinder.norm = norm;
	cylinder.color = color;
	cylinder.dia = size_info[0];
	cylinder.height = size_info[1];
	return (cylinder);
}

t_cylinder	*create_cylinder(t_vect pos, t_vect norm, t_color color,
				double size_info[2])
{
	t_cylinder			*ptr_new_cylinder;

	ptr_new_cylinder = malloc(sizeof(*ptr_new_cylinder));
	if (!ptr_new_cylinder)
	{
		perror("Could not allocate memory");
		exit(errno);
	}
	*ptr_new_cylinder = cylinder(pos, norm, color, size_info);
	return (ptr_new_cylinder);
}

void	delete_cylinder(t_cylinder *ptr_cylinder)
{
	free(ptr_cylinder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:01:41 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/09 23:53:06 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "plane.h"

t_plane	plane(t_vect pos, t_vect norm, t_color color)
{
	t_plane	plane;

	plane.pos = pos;
	plane.norm = norm;
	plane.color = color;
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

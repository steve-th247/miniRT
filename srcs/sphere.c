/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:24:20 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/22 21:31:58 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "sphere.h"

t_sphere	sphere(t_vect pos, double dia, t_color color)
{
	t_sphere	sphere;

	sphere.pos = pos;
	sphere.dia = dia;
	sphere.color = color;
	sphere.translate = translate_sphere;
	sphere.rotate = NULL;
	sphere.resize_1 = resize_sphere;
	sphere.resize_2 = NULL;
	return (sphere);
}

t_sphere	*create_sphere(t_vect pos, double dia, t_color color)
{
	t_sphere			*ptr_new_sphere;

	ptr_new_sphere = malloc(sizeof(*ptr_new_sphere));
	if (!ptr_new_sphere)
	{
		perror("Could not allocate memory");
		exit(errno);
	}
	*ptr_new_sphere = sphere(pos, dia, color);
	return (ptr_new_sphere);
}

void	delete_sphere(t_sphere *ptr_sphere)
{
	free(ptr_sphere);
}

void	translate_sphere(t_sphere *sphere, t_vect vector)
{
	sphere->pos = add(sphere->pos, vector);
}

void	resize_sphere(t_sphere *sphere, double delta)
{
	sphere->dia += delta;
	if (sphere->dia < 1e-4)
		sphere->dia = 0;
}

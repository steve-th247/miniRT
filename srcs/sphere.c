/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:24:20 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/09 23:53:03 by tjien-ji         ###   ########.fr       */
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

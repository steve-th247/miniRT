/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:24:59 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/08 18:46:55 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include "vect.h"

t_vect	vect(double x, double y, double z)
{
	t_vect	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vect	*create_vect(double x, double y, double z)
{
	t_vect			*ptr_new_vect;

	ptr_new_vect = malloc(sizeof(*ptr_new_vect));
	*ptr_new_vect = vect(x, y, z);
	return (ptr_new_vect);
}

void	delete_vect(t_vect *ptr_vect)
{
	free(ptr_vect);
}

char	vect_is_equal(t_vect v1, t_vect v2)
{
	if (fabs(v1.x - v2.x) > 1e-4
		|| fabs(v1.y - v2.y) > 1e-4
		|| fabs(v1.z - v2.z) > 1e-4)
		return (0);
	return (1);
}

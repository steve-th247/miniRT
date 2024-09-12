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

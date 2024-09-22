/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:29:30 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/23 00:35:22 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "generic_obj.h"
#include "vect.h"

void	translate_obj(t_generic_obj *obj, t_vect vector)
{
	if (obj != NULL && obj->translate != NULL)
		obj->translate(obj, vector);
}

void	rotate_obj(t_generic_obj *obj, t_vect vector)
{
	if (obj != NULL && obj->rotate != NULL)
		obj->rotate(obj, vector);
}

void	resize_obj_1(t_generic_obj *obj, double diff)
{
	if (obj != NULL && obj->resize_1 != NULL)
		obj->resize_1(obj, diff);
}

void	resize_obj_2(t_generic_obj *obj, double diff)
{
	if (obj != NULL && obj->resize_2 != NULL)
		obj->resize_2(obj, diff);
}

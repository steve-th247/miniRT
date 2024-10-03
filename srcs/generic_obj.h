/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_obj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:54:31 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/10/03 18:32:53 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_OBJ_H
# define GENERIC_OBJ_H

# include "vect.h"

typedef struct s_generic_obj	t_generic_obj;

struct s_generic_obj
{
	void	(*translate)(t_generic_obj *, t_vect);
	void	(*rotate)(t_generic_obj *, t_vect, double);
	void	(*resize_1)(t_generic_obj *, double);
	void	(*resize_2)(t_generic_obj *, double);
};

void	translate_obj(t_generic_obj *obj, t_vect vector);
void	rotate_obj(t_generic_obj *obj, t_vect axis, double deg);
void	resize_obj_1(t_generic_obj *obj, double diff);
void	resize_obj_2(t_generic_obj *obj, double diff);

#endif

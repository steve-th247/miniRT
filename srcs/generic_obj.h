/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_obj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:54:31 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/22 20:59:55 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect.h"

typedef struct s_generic_obj	t_generic_obj;

struct s_generic_obj
{
	void	(*translate)(t_generic_obj *, t_vect);
	void	(*rotate)(t_generic_obj *, t_vect);
	void	(*resize_1)(t_generic_obj *, double);
	void	(*resize_2)(t_generic_obj *, double);
};

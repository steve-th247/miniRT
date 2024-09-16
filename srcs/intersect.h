/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:59:11 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:02:35 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "vect.h"
# include "color.h"
# include "obj.h"

typedef struct s_inter
{
	int			i;
	t_obj_type	type;
	void		*obj_ptr;
	double		dist;
	t_vect		point;
	t_vect		normal;
	t_color		color;
}	t_inter;

#endif
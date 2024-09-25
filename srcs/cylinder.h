/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:28:10 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 17:30:58 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vect.h"
# include "color.h"

typedef struct s_cylinder	t_cylinder;

struct s_cylinder
{
	void	(*translate)(t_cylinder *, t_vect);
	void	(*rotate)(t_cylinder *, t_vect);
	void	(*resize_1)(t_cylinder *, double);
	void	(*resize_2)(t_cylinder *, double);
	int		i;
	t_vect	pos;
	t_vect	norm_axis;
	t_color	color;
	double	dia;
	double	height;
};

t_cylinder	cylinder(t_vect pos, t_vect norm_axis, t_color color,
				double size_info[2]);
t_cylinder	*create_cylinder(t_vect pos, t_vect norm_axis, t_color color,
				double size_info[2]);
void		delete_cylinder(t_cylinder *ptr_cylinder);
void		translate_cylinder(t_cylinder *cyl, t_vect vector);
void		rotate_cylinder(t_cylinder *cyl, t_vect target_z);

void		resize_cylinder_1(t_cylinder *cyl, double diff);
void		resize_cylinder_2(t_cylinder *cyl, double diff);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:44:40 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 18:19:43 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "vect.h"
#include "color.h"

typedef struct s_light
{
	int		i;
	float	ratio;
	t_vect	pos;
}	t_light;

typedef struct s_amb
{
	int		i;
	float	ratio;
	t_color	color;
}	t_amb;

#endif
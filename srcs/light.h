/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:44:40 by jyap              #+#    #+#             */
/*   Updated: 2024/09/20 07:57:19 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vect.h"
# include "color.h"

typedef struct s_light
{
	int		i;
	float	ratio;
	t_vect	pos;
	t_color	color;
}	t_light;

typedef struct s_amb
{
	int		i;
	float	ratio;
	t_color	color;
}	t_amb;

#endif

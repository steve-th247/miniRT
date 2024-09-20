/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:33:00 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/20 13:35:26 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "vect.h"

t_color	add_color(t_color color1, t_color color2, t_color color3)
{
	t_color	color;

	color.r = (color1.r + color2.r + color3.r) / 3;
	color.g = (color1.g + color2.g + color3.g) / 3;
	color.b = (color1.b + color2.b + color3.b) / 3;
	return (color);
}

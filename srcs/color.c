/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:16:02 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/20 14:02:55 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include "color.h"

t_color	color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	*create_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color			*ptr_new_color;

	ptr_new_color = malloc(sizeof(*ptr_new_color));
	if (!ptr_new_color)
	{
		perror("Could not allocate memory");
		exit(errno);
	}
	*ptr_new_color = color(r, g, b);
	return (ptr_new_color);
}

void	delete_color(t_color *ptr_color)
{
	free(ptr_color);
}

unsigned int	get_trgb(t_color color, unsigned char t)
{
	if (t)
		return (t << 24 | color.r << 16 | color.g << 8 | color.b);
	return (color.r << 16 | color.g << 8 | color.b);
}

t_color	scale_color(t_color color, double scale_factor)
{
	color.r = fmin(color.r * scale_factor, 255.0);
	color.g = fmin(color.g * scale_factor, 255.0);
	color.b = fmin(color.b * scale_factor, 255.0);
	return (color);
}

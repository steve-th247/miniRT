/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:16:02 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/09 23:51:38 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
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

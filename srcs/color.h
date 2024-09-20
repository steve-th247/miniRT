/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:14:36 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/20 07:57:36 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

t_color			color(unsigned char r, unsigned char g, unsigned char b);
t_color			*create_color(unsigned char r,
					unsigned char g, unsigned char b);
void			delete_color(t_color *ptr_color);
unsigned int	get_trgb(t_color color, unsigned char t);
t_color			scale_color(t_color color, double scale_factor);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:50:57 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/22 21:55:33 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	resize_cylinder_1(t_cylinder *cyl, double diff)
{
	cyl->dia += diff;
	if (cyl->dia < 1e-4)
		cyl->dia = 0;
}

void	resize_cylinder_2(t_cylinder *cyl, double diff)
{
	cyl->height += diff;
	if (cyl->height < 1e-4)
		cyl->height = 0;
}

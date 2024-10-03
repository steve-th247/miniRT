/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:01:39 by jyap              #+#    #+#             */
/*   Updated: 2024/10/03 18:31:16 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vect.h"
# include "intersect.h"

typedef struct s_ray
{
	t_vect	dir;
	t_vect	pos;
	t_inter	inter;
}	t_ray;

#endif

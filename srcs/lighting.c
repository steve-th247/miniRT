/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:33:38 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/23 08:28:32 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

t_color	color_ambient(const t_mlxs *mlxs)
{
	return (scale_color(mlxs->sc->amb.color, mlxs->sc->amb.ratio));
}

t_color	color_diffuse(t_mlxs *mlxs, t_inter *inter)
{
	t_ray	ray2;
	double	dot_prod;
	double	dist_attenuation_factor;

	ray2.dir = normalize(sub(mlxs->sc->light.pos, inter->point));
	ray2.pos = inter->point;
	closest_inter(mlxs, &ray2);
	if (ray2.inter.i != -1
		&& (ray2.inter.dist - distance(ray2.pos, mlxs->sc->light.pos)) > -1e-4)
		ray2.inter.i = -1;
	if (ray2.inter.i == -1 || (vect_is_equal(ray2.inter.point, ray2.pos)))
	{
		dot_prod = dot_product(inter->normal, ray2.dir);
		if (dot_prod < 1e-4)
			dot_prod = 0;
		dist_attenuation_factor = fmin(75 / ray2.inter.dist, 1);
		return (scale_color(mlxs->sc->light.color,
				dot_prod * mlxs->sc->light.ratio * dist_attenuation_factor));
	}
	return (color(0, 0, 0));
}

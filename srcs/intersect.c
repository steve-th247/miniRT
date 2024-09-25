/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:27:50 by jyap              #+#    #+#             */
/*   Updated: 2024/09/25 23:00:50 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool	is_closest(t_inter *closest, t_inter temp)
{
	if (closest->dist == INFINITY && temp.dist != INFINITY && temp.dist > 1e-4)
		return (true);
	if (temp.dist < closest->dist && fabs(closest->dist - temp.dist) > 1e-4)
		return (true);
	return (false);
}

void	closest_inter_sub(t_inter *closest, t_inter temp, t_obj *obj)
{
	if (!is_closest(closest, temp))
		return ;
	*closest = temp;
	closest->i = obj->i;
}

void	closest_inter(t_mlxs *mlxs, t_ray *ray)
{
	t_inter		closest;
	t_inter		temp;
	t_obj		*obj;

	closest.dist = INFINITY;
	closest.i = -1;
	closest.color = color(0, 0, 0);
	obj = mlxs->sc->obj;
	while (obj)
	{
		if (obj->type == PLANE)
			temp = intersect_plane(ray, (t_plane *)obj->obj_ptr);
		else if (obj->type == SPHERE)
			temp = intersect_sphere(ray, (t_sphere *)obj->obj_ptr);
		else if (obj->type == CYLINDER)
			temp = intersect_cylinder(ray, (t_cylinder *) obj->obj_ptr);
		closest_inter_sub(&closest, temp, obj);
		obj = obj->next;
	}
	ray->inter = closest;
}

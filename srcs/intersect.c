/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:27:50 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 19:06:35 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool is_closest(t_inter *closest, t_inter *temp)
{
	if (temp->dist == INFINITY || temp->dist < 0)
		return (false);
	if (closest->dist == INFINITY)
		return (true);
	else if (temp->dist < closest->dist)
		return (true);
	return (false);
}

void	closest_inter(t_mlxs *mlxs, t_ray *ray)
{
	t_inter		*closest;
	t_inter		*temp;
	t_obj		*obj;

	closest = ft_calloc(sizeof(t_inter), 1);
	if (closest == NULL)
		print_err_exit("Malloc failed.\n", &mlxs, NULL);
	closest->dist = INFINITY;
	obj = mlxs->sc->obj;
	while (obj)
	{
		closest->i = obj->i;
		if (obj->type == PLANE)
			temp = intersect_plane(ray, (t_plane *)obj->obj_ptr);
		else if (obj->type == SPHERE)
			temp = intersect_sphere(ray, (t_sphere *)obj->obj_ptr);
		else if (obj->type == CYLINDER)
			temp = intersect_cylinder(ray, (t_cylinder *) obj->obj_ptr);
		if (temp == NULL)
		{
			free(closest);
			print_err_exit("Malloc failed.\n", &mlxs, NULL);
		}
		if (is_closest(closest, temp))
		{
			free(closest);
			closest = temp;
		}
		else
			free(temp);
		obj = obj->next;
	}
	ray->inter = closest;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controls2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:14:58 by jyap              #+#    #+#             */
/*   Updated: 2024/09/25 16:36:08 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_plane_controls(t_plane *pl)
{
	printf("Currently selected : Plane\n");
	printf("--------------------------\n\n");
	printf("Coordinates of a point in the plane :(%.3f, %.3f, %.3f)\n\n",
		pl->pos.x, pl->pos.y, pl->pos.z);
	printf("Plane Normal :(%.3f, %.3f, %.3f)\n",
		pl->norm.x, pl->norm.y, pl->norm.z);
}

void	print_sphere_controls(t_sphere *sp)
{
	printf("Use Mouse Scroll to set diameter of sphere\n\n");
	printf("Currently selected : Sphere\n\n");
	printf("Coordinates :(%.3f, %.3f, %.3f)\n\n",
		sp->pos.x, sp->pos.y, sp->pos.z);
	printf("Diameter : %.3f\n", sp->dia);
}

void	print_cylinder_controls(t_cylinder *cy)
{
	printf("Set Height\n");
	print_signs();
	printf("Use Mouse Scroll to set diameter of cylinder\n\n");
	printf("Currently selected : Cylinder\n");
	printf("-----------------------------\n\n");
	printf("Coordinates :(%.3f, %.3f, %.3f)\n\n",
		cy->pos.x, cy->pos.y, cy->pos.z);
	printf("Diameter : %.3f\n\n", cy->dia);
	printf("Height : %.3f\n\n", cy->height);
	printf("Normalized Vector of axis :(%.3f, %.3f, %.3f)\n",
		cy->norm_axis.x, cy->norm_axis.y, cy->norm_axis.z);
}

void	print_obj_controls(void *obj)
{
	t_plane	*shape;
	int		type;

	shape = (t_plane *)obj;
	type = shape->i;
	print_mode();
	print_transform();
	if (type == PLANE)
		print_plane_controls((t_plane *)obj);
	else if (type == SPHERE)
		print_sphere_controls((t_sphere *)obj);
	else
		print_cylinder_controls((t_cylinder *)obj);
}

void	print_controls(t_mlxs *mlxs)
{
	printf("\033[1J\n");
	if (mlxs->last_selected_obj == &mlxs->sc->light)
		print_light_controls(mlxs->sc->light);
	else if (mlxs->last_selected_obj != NULL)
		print_obj_controls(mlxs->last_selected_obj);
	else
		print_cam_controls(mlxs->sc->cam);
}

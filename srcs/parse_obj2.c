/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:07:53 by jyap              #+#    #+#             */
/*   Updated: 2024/09/22 22:09:22 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	parse_obj_plane(t_obj *new_obj, char *line, t_mlxs *mlxs)
{
	new_obj->type = PLANE;
	new_obj->obj_ptr = create_plane(vect(0, 0, 0), vect(0, 0, 0),
			color(0, 0, 0));
	parse_plane(line, mlxs, new_obj);
}

void	parse_obj_sphere(t_obj *new_obj, char *line, t_mlxs *mlxs)
{
	new_obj->type = SPHERE;
	new_obj->obj_ptr = create_sphere(vect(0, 0, 0), 0, color(0, 0, 0));
	parse_sphere(line, mlxs, new_obj);
}

void	parse_obj_cylinder(t_obj *new_obj, char *line, t_mlxs *mlxs)
{
	new_obj->type = CYLINDER;
	new_obj->obj_ptr = create_cylinder(vect(0, 0, 0), vect(0, 0, 0),
			color(0, 0, 0), (double [2]){0, 0});
	parse_cylinder(line, mlxs, new_obj);
}

void	parse_obj(char *line, t_mlxs *mlxs, t_obj_type type)
{
	t_obj		*new_obj;
	static int	i;

	new_obj = ft_calloc(sizeof(t_obj), 1);
	new_obj->type = 0;
	new_obj->obj_ptr = NULL;
	if (new_obj == NULL)
		print_err_exit("Malloc failed.\n", &mlxs, line);
	mlxs->new_obj = new_obj;
	if (type == PLANE)
		parse_obj_plane(new_obj, line, mlxs);
	else if (type == SPHERE)
		parse_obj_sphere(new_obj, line, mlxs);
	else if (type == CYLINDER)
		parse_obj_cylinder(new_obj, line, mlxs);
	new_obj->next = NULL;
	new_obj->i = i++;
	object_add_end(&mlxs->sc->obj, new_obj);
	mlxs->new_obj = NULL;
}

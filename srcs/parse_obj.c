/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:27:51 by jyap              #+#    #+#             */
/*   Updated: 2024/09/25 17:28:12 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	parse_plane(char *line, t_mlxs *mlxs, t_obj *new_obj)
{
	char		**split;
	t_plane		*plane;

	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Mallco ft_split failed.\n", &mlxs, line);
	plane = (t_plane *)new_obj->obj_ptr;
	if (count_arr_elements(split) != 4)
	{
		free_str_arr(split);
		print_err_exit("Invalid info for Plane.\n", &mlxs, line);
	}
	plane->pos = parse_coord(split, 1, line, mlxs);
	plane->norm = normalize(parse_vector(split, 2, line, mlxs));
	plane->color = parse_color(split, 3, line, mlxs);
	plane->i = PLANE;
	free_str_arr(split);
}

void	parse_sphere(char *line, t_mlxs *mlxs, t_obj *new_obj)
{
	char		**split;
	t_sphere	*sphere;

	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Mallco ft_split failed.\n", &mlxs, line);
	sphere = (t_sphere *)new_obj->obj_ptr;
	if (count_arr_elements(split) != 4)
	{
		free_str_arr(split);
		print_err_exit("Invalid info for Sphere.\n", &mlxs, line);
	}
	sphere->pos = parse_coord(split, 1, line, mlxs);
	sphere->dia = parse_dia_height(split, 2, line, mlxs);
	sphere->color = parse_color(split, 3, line, mlxs);
	sphere->i = SPHERE;
	free_str_arr(split);
}

void	parse_cylinder(char *line, t_mlxs *mlxs, t_obj *new_obj)
{
	char		**split;
	t_cylinder	*cylinder;

	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Mallco ft_split failed.\n", &mlxs, line);
	cylinder = (t_cylinder *)new_obj->obj_ptr;
	if (count_arr_elements(split) != 6)
	{
		free_str_arr(split);
		print_err_exit("Invalid info for Cylinder.\n", &mlxs, line);
	}
	cylinder->pos = parse_coord(split, 1, line, mlxs);
	cylinder->norm_axis = normalize(parse_vector(split, 2, line, mlxs));
	cylinder->dia = parse_dia_height(split, 3, line, mlxs);
	cylinder->height = parse_dia_height(split, 4, line, mlxs);
	cylinder->color = parse_color(split, 5, line, mlxs);
	cylinder->i = CYLINDER;
	free_str_arr(split);
}

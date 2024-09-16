/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:40:26 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:53:06 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

float	parse_ratio(char **arr, int i, char *line, t_mlxs *mlxs)
{
	float	ratio;

	ratio = 0;
	if (is_float(arr[i]) == false)
	{
		free_str_arr(arr);
		print_err_exit("Ratio info is not valid.\n", &mlxs, line);
	}
	ratio = str_to_float(arr[i]);
	if (ratio >= 0 && ratio <= 1)
		return (ratio);
	else
	{
		free_str_arr(arr);
		print_err_exit("Ratio not within range.\n", &mlxs, line);
		return (0);
	}
}

t_color	parse_color(char **arr, int i, char *line, t_mlxs *mlxs)
{
	char	**split;
	int		ret;
	t_color	col;

	ret = 0;
	ft_bzero(&col, sizeof(t_color));
	split = ft_split(arr[i], ',');
	if (split == NULL)
	{
		free_str_arr(arr);
		print_err_exit("Malloc for ft_split failed.\n", &mlxs, line);
	}
	ret = is_color(split[0]) + is_color(split[1]) + is_color(split[2]);
	if (count_arr_elements(split) != 3 || ret != 3)
	{
		free_str_arr(arr);
		free_str_arr(split);
		print_err_exit("Invalid info for colors.\n", &mlxs, line);
	}
	col.r = ft_atoi(split[0]);
	col.g = ft_atoi(split[1]);
	col.b = ft_atoi(split[2]);
	free_str_arr(split);
	return (col);
}

t_vect	parse_coord(char **arr, int i, char *line, t_mlxs *mlxs)
{
	char	**split;
	int		ret;
	t_vect	coord;

	ret = 0;
	ft_bzero(&coord, sizeof(t_vect));
	split = ft_split(arr[i], ',');
	if (split == NULL)
	{
		free_str_arr(arr);
		print_err_exit("Malloc for ft_split failed.\n", &mlxs, line);
	}
	ret = is_float(split[0]) + is_float(split[1]) + is_float(split[2]);
	if (count_arr_elements(split) != 3 || ret != 3)
	{
		free_str_arr(arr);
		free_str_arr(split);
		print_err_exit("Invalid info for coordinates.\n", &mlxs, line);
	}
	coord.x = (double)str_to_float(split[0]);
	coord.y = (double)str_to_float(split[1]);
	coord.z = (double)str_to_float(split[2]);
	free_str_arr(split);
	return (coord);
}

t_vect	parse_vector_sub(char **arr, char **split, char *line, t_mlxs *mlxs)
{
	int		ret;
	t_vect	vect;

	ret = is_float(split[0]) + is_float(split[1]) + is_float(split[2]);
	if (ret == 3)
	{
		vect.x = (double)str_to_float(split[0]);
		vect.y = (double)str_to_float(split[1]);
		vect.z = (double)str_to_float(split[2]);
		ret += is_range(vect.x) + is_range(vect.y) + is_range(vect.x);
	}
	free_str_arr(split);
	if (ret != 6)
	{
		free_str_arr(arr);
		print_err_exit("Invalid info for normalized vector.\n", &mlxs, line);
	}
	return (vect);
}

t_vect	parse_vector(char **arr, int i, char *line, t_mlxs *mlxs)
{
	char	**split;
	t_vect	vect;

	ft_bzero(&vect, sizeof(t_vect));
	split = ft_split(arr[i], ',');
	if (split == NULL)
	{
		free_str_arr(arr);
		print_err_exit("Malloc for ft_split failed.\n", &mlxs, line);
	}
	if (count_arr_elements(split) != 3)
	{
		free_str_arr(split);
		free_str_arr(arr);
		print_err_exit("Invalid info for normalized vector.\n", &mlxs, line);
	}
	vect = parse_vector_sub(arr, split, line, mlxs);
	return (vect);
}

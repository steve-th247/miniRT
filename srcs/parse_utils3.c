/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:06:37 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:50:01 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

t_obj	*last_object(t_obj	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	object_add_end(t_obj **lst, t_obj *new)
{
	t_obj	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = last_object(*lst);
	last->next = new;
}

unsigned char	parse_camera_fov(char **arr, int i, char *line, t_mlxs *mlxs)
{
	char	**split;
	int		fov;

	split = ft_split(arr[i], ',');
	fov = 0;
	if (split == NULL)
		arr_exit("Malloc for ft_split failed.\n", &mlxs, arr, line);
	if (count_arr_elements(split) != 1)
	{
		free_str_arr(split);
		arr_exit("Invalid info for camera FOV.\n", &mlxs, arr, line);
	}
	free_str_arr(split);
	if (is_float(arr[i]) == false)
		arr_exit("Invalid info for camera FOV.\n", &mlxs, arr, line);
	fov = ft_atoi(arr[i]);
	if (!(fov >= 0 && fov <= 180))
		arr_exit("Camera FOV must be between 0 and 180.\n", &mlxs, arr, line);
	return ((unsigned char)fov);
}

double	parse_dia_height(char **arr, int i, char *line, t_mlxs *mlxs)
{
	char	**split;
	double	ret;

	ret = 0;
	split = ft_split(arr[i], ',');
	if (split == NULL)
		arr_exit("Malloc for ft_split failed.\n", &mlxs, arr, line);
	if (count_arr_elements(split) != 1)
	{
		free_two_str_arr(split, arr);
		print_err_exit("Invalid info for Diameter/Height.\n", &mlxs, line);
	}
	free_str_arr(split);
	if (is_float(arr[i]) == false)
		arr_exit("Diameter/Height must be a float.\n", &mlxs, arr, line);
	ret = (double)str_to_float(arr[i]);
	if (ret <= 0)
		arr_exit("Diameter/Height must be larger than 0.\n", &mlxs, arr, line);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:13:50 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:08:24 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	free_str_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_two_str_arr(char **arr1, char **arr2)
{
	free_str_arr(arr1);
	free_str_arr(arr2);
}

void	free_obj_list(t_obj *obj)
{
	t_obj	*tmp;

	if (obj == NULL)
		return ;
	while (obj)
	{
		tmp = obj->next;
		if (obj->obj_ptr != NULL)
		{
			free(obj->obj_ptr);
			obj->obj_ptr = NULL;
		}
		free(obj);
		obj = tmp;
	}
}

void	free_scene(t_scene *sc)
{
	if (sc == NULL)
		return ;
	if (sc->obj != NULL)
		free_obj_list(sc->obj);
	free(sc);
}

void	free_all(t_mlxs *mlxs)
{
	if (mlxs)
	{
		if (mlxs->img.img)
			mlx_destroy_image(mlxs->mlx, mlxs->img.img);
		if (mlxs->mlx_win)
			mlx_destroy_window(mlxs->mlx, mlxs->mlx_win);
		if (mlxs->mlx)
			mlx_destroy_display(mlxs->mlx);
		if (mlxs->new_obj != NULL)
		{
			if (mlxs->new_obj->obj_ptr != NULL)
			{
				free(mlxs->new_obj->obj_ptr);
				mlxs->new_obj->obj_ptr = NULL;
			}
			free(mlxs->new_obj);
			mlxs->new_obj = NULL;
		}
		free_scene(mlxs->sc);
		mlxs->sc = NULL;
		free(mlxs);
	}
}

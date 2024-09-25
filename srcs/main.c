/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:07:00 by jyap              #+#    #+#             */
/*   Updated: 2024/09/25 17:47:26 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	destroy(t_mlxs *mlxs)
{
	free_all(mlxs);
	exit (0);
	return (0);
}

int	render(t_mlxs *mlxs)
{
	launch_rays_from_camera(mlxs);
	mlx_put_image_to_window(mlxs->mlx, mlxs->mlx_win, \
	mlxs->img.img, 0, 0);
	print_controls(mlxs);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlxs	*mlxs;

	(void) av;
	if (ac != 2)
	{
		print_err("Invalid Arguments.\n", NULL);
		print_err_exit("./miniRT <file.rt>\n", NULL, NULL);
	}
	mlxs = ft_calloc(sizeof(t_mlxs), 1);
	mlxs->last_selected_obj = NULL;
	if (mlxs == NULL)
		print_err_exit("Malloc mlxs failed.\n", NULL, NULL);
	parse(av[1], mlxs);
	init_mlx(mlxs);
	mlxs->arr_obj_ptrs = ft_calloc(WIN_H * WIN_W, sizeof(void *));
	if (mlxs->arr_obj_ptrs == NULL)
		print_err_exit("Malloc failed.\n", NULL, NULL);
	render(mlxs);
	init_mlx_hook(mlxs);
	mlx_loop(mlxs->mlx);
	destroy(mlxs);
	return (0);
}

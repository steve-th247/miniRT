/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:07:00 by jyap              #+#    #+#             */
/*   Updated: 2024/09/21 22:20:47 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	handle_key(const int keycode, t_mlxs *mlxs)
{
	if (keycode == 65307)
	{
		free_all(mlxs);
		exit (0);
	}
	return (0);
}

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
	if (mlxs == NULL)
		print_err_exit("Malloc mlxs failed.\n", NULL, NULL);
	parse(av[1], mlxs);
	init_mlx(mlxs);
	mlxs->arr_obj_ptrs = ft_calloc(WIN_H * WIN_W, sizeof(void *));
	if (mlxs->arr_obj_ptrs == NULL)
		print_err_exit("Malloc failed.\n", NULL, NULL);
	render(mlxs);
	mlx_hook(mlxs->mlx_win, 17, 0, destroy, mlxs);
	mlx_key_hook(mlxs->mlx_win, handle_key, mlxs);
	mlx_loop(mlxs->mlx);
	return (0);
}

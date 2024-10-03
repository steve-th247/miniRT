/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:07:00 by jyap              #+#    #+#             */
/*   Updated: 2024/10/03 18:27:11 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	destroy(t_mlxs *mlxs)
{
	free_all(mlxs);
	printf("\033[2J\033[H");
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
		print_err_exit("Invalid Arguments.\n./miniRT <file.rt>\n", NULL, NULL);
	mlxs = ft_calloc(sizeof(t_mlxs), 1);
	mlxs->last_selected_obj = NULL;
	if (mlxs == NULL)
		print_err_exit("Malloc mlxs failed.\n", NULL, NULL);
	parse(av[1], mlxs);
	init_mlx(mlxs);
	mlxs->arr_obj_ptrs = ft_calloc(WIN_H * WIN_W, sizeof(void *));
	if (mlxs->arr_obj_ptrs == NULL)
		print_err_exit("Malloc failed.\n", &mlxs, NULL);
	render(mlxs);
	init_mlx_hook(mlxs);
	mlx_loop(mlxs->mlx);
	destroy(mlxs);
	return (0);
}

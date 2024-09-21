/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:07:00 by jyap              #+#    #+#             */
/*   Updated: 2024/09/21 19:26:34 by tjien-ji         ###   ########.fr       */
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
	mlxs->mlx = mlx_init();
	mlxs->mlx_win = mlx_new_window(mlxs->mlx, WIN_W,
			WIN_H, "miniRT");
	mlxs->img.img = mlx_new_image(mlxs->mlx, WIN_W, WIN_H);
	mlxs->img.addr = mlx_get_data_addr(mlxs->img.img,
			&mlxs->img.bits_per_pixel, &mlxs->img.line_length,
			&mlxs->img.endian);
	render(mlxs);
	mlx_hook(mlxs->mlx_win, 17, 0, destroy, mlxs);
	mlx_key_hook(mlxs->mlx_win, handle_key, mlxs);
	mlx_loop(mlxs->mlx);
	return (0);
}

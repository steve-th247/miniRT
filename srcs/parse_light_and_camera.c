/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_and_camera.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:03:12 by jyap              #+#    #+#             */
/*   Updated: 2024/09/20 14:35:29 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	count_arr_elements(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	parse_amb(char *line, t_mlxs *mlxs)
{
	char		**split;
	t_amb		amb;

	if (mlxs->sc->amb.i != 0)
		print_err_exit("Maximum of 1 Ambient Lighting accepted.\n",
			&mlxs, line);
	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Malloc ft_split failed.\n", &mlxs, line);
	ft_bzero(&amb, sizeof(t_amb));
	amb.i = 1;
	if (count_arr_elements(split) != 3)
	{
		free_str_arr(split);
		print_err_exit("Wrong number of info for Ambient Lighting.\n",
			&mlxs, line);
	}
	amb.ratio = parse_ratio(split, 1, line, mlxs);
	amb.color = parse_color(split, 2, line, mlxs);
	mlxs->sc->amb = amb;
	free_str_arr(split);
}

void	parse_light(char *line, t_mlxs *mlxs)
{
	t_light	light;
	char	**split;

	if (mlxs->sc->light.i != 0)
		print_err_exit("Maximum of 1 Light accepted.\n", &mlxs, line);
	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Malloc ft_split failed.\n", &mlxs, line);
	ft_bzero(&light, sizeof(t_light));
	light.i = 1;
	if (count_arr_elements(split) != 3)
	{
		free_str_arr(split);
		print_err_exit("Wrong number of info for Light.\n", &mlxs, line);
	}
	light.pos = parse_coord(split, 1, line, mlxs);
	light.ratio = parse_ratio(split, 2, line, mlxs);
	light.color = color(255, 255, 255);
	mlxs->sc->light = light;
	free_str_arr(split);
}

void	parse_camera(char *line, t_mlxs *mlxs)
{
	t_camera	cam;
	char		**split;

	if (mlxs->sc->cam.i != 0)
		print_err_exit("Only 1 Camera accepted.\n", &mlxs, line);
	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Malloc ft_split failed.\n", &mlxs, line);
	ft_bzero(&cam, sizeof(t_camera));
	cam.i = 1;
	if (count_arr_elements(split) != 4)
	{
		free_str_arr(split);
		print_err_exit("Wrong number of info for Camera.\n", &mlxs, line);
	}
	cam.pos = parse_coord(split, 1, line, mlxs);
	cam.norm = normalize(parse_vector(split, 2, line, mlxs));
	cam.fov_deg = parse_camera_fov(split, 3, line, mlxs);
	mlxs->sc->cam = cam;
	free_str_arr(split);
}

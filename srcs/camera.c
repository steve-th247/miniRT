/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:07:32 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 02:02:53 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "camera.h"

t_camera	camera(t_vect pos, t_vect norm, unsigned char fov_deg)
{
	t_camera	camera;

	camera.pos = pos;
	camera.norm = norm;
	camera.fov_deg = fov_deg;
	return (camera);
}

t_camera	*create_camera(t_vect pos, t_vect norm, unsigned char fov_deg)
{
	t_camera			*ptr_new_camera;

	ptr_new_camera = malloc(sizeof(*ptr_new_camera));
	if (!ptr_new_camera)
	{
		perror("Could not allocate memory");
		exit(errno);
	}
	*ptr_new_camera = camera(pos, norm, fov_deg);
	return (ptr_new_camera);
}

void	delete_camera(t_camera *ptr_camera)
{
	free(ptr_camera);
}

void	set_cam_norm(t_camera *cam, t_vect norm)
{
	cam->norm = norm;
	cam->u = cross_product(vect(0, 1, 0), cam->norm);
	if (vect_is_equal(cam->norm, vect(0, 1, 0)))
		cam->u = cross_product(vect(0, 0, -1), cam->norm);
	cam->v = cross_product(cam->norm, cam->u);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:16:02 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 02:16:02 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vect.h"

void	rotate_cam_x(t_camera *cam, double deg)
{
	cam->v = rotate_around_axis(cam->v, cam->u, deg);
	cam->norm = rotate_around_axis(cam->norm, cam->u, deg);
}

void	rotate_cam_y(t_camera *cam, double deg)
{
	cam->u = rotate_around_axis(cam->u, cam->v, deg);
	cam->norm = rotate_around_axis(cam->norm, cam->v, deg);
}

void	rotate_cam_z(t_camera *cam, double deg)
{
	cam->u = rotate_around_axis(cam->u, cam->norm, deg);
	cam->v = rotate_around_axis(cam->v, cam->norm, deg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:03:59 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 02:10:22 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vect.h"

typedef struct s_camera
{
	int				i;
	t_vect			pos;
	t_vect			norm;
	unsigned char	fov_deg;
	t_vect			u;
	t_vect			v;
	t_vect			w;
}	t_camera;

t_camera	camera(t_vect pos, t_vect norm, unsigned char fov_deg);
t_camera	*create_camera(t_vect pos, t_vect norm, unsigned char fov_deg);
void		delete_camera(t_camera *ptr_camera);
void		set_cam_norm(t_camera *cam, t_vect norm);

void		rotate_cam_x(t_camera *cam, double deg);
void		rotate_cam_y(t_camera *cam, double deg);
void		rotate_cam_z(t_camera *cam, double deg);

#endif

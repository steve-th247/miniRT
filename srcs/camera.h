/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:03:59 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/14 18:16:47 by jyap             ###   ########.fr       */
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
}	t_camera;

t_camera	camera(t_vect pos, t_vect norm, unsigned char fov_deg);
t_camera	*create_camera(t_vect pos, t_vect norm, unsigned char fov_deg);
void		delete_camera(t_camera *ptr_camera);

#endif

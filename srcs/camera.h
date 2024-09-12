/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:03:59 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/09 23:06:45 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vect.h"

typedef struct s_camera
{
	t_vect			pos;
	t_vect			norm;
	unsigned char	fov_deg;
}	t_camera;

t_camera	camera(t_vect pos, t_vect norm, unsigned char fov_deg);
t_camera	*create_camera(t_vect pos, t_vect norm, unsigned char fov_deg);
void		delete_camera(t_camera *ptr_camera);

#endif

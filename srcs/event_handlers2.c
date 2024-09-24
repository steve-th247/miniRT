/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 06:04:31 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/24 13:20:31 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "mlx_structs.h"
#include "generic_obj.h"
#include <math.h>
#include <X11/keysym.h>

void	kb_event_handler_transform_cam(int keycode, t_mlxs *mlxs)
{
	if (keycode == XK_KP_Add || keycode == XK_KP_Subtract)
		kb_event_handler_zoom_cam(keycode, mlxs);
	else if (keycode == XK_w || keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_Up || keycode == XK_Down)
		kb_event_handler_translate_cam(keycode, mlxs);
	else if (keycode == XK_KP_Left || keycode == XK_KP_Right
		|| keycode == XK_KP_Up || keycode == XK_KP_Down)
		kb_event_handler_rotate_cam(keycode, mlxs);
}

/*void	kb_event_handler_rotate_cam(int keycode, t_mlxs *mlxs)
{
	t_vect	target_z;

	target_z = vect(0, 0, 1);
	if (keycode == XK_KP_Left)
		target_z = vect(-0.196116, 0, 0.980581);
	else if (keycode == XK_KP_Right)
		target_z = vect(0.196116, 0, 0.980581);
	else if (keycode == XK_KP_Up)
		target_z = vect(0, -0.196116, 0.980581);
	else if (keycode == XK_KP_Down)
		target_z = vect(0, 0.196116, 0.980581);
	mlxs->sc->cam.norm = rotate_vector(mlxs->sc->cam.norm, target_z);
}*/

void	kb_event_handler_rotate_cam_updown(int keycode,
	t_mlxs *mlxs, t_vect right)
{
	t_vect	cam_ori;

	cam_ori = mlxs->sc->cam.norm;
	if (keycode == XK_KP_Up)
	{
		if (mlxs->sc->cam.updown_angle - 10 < -90)
			return ;
		mlxs->sc->cam.norm = rotate_around_axis(cam_ori, right, -10);
		mlxs->sc->cam.updown_angle -= 10;
	}
	else
	{
		if (mlxs->sc->cam.updown_angle + 10 > 90)
			return ;
		mlxs->sc->cam.norm = rotate_around_axis(cam_ori, right, 10);
		mlxs->sc->cam.updown_angle += 10;
	}
}

void	kb_event_handler_rotate_cam(int keycode, t_mlxs *mlxs)
{
	t_vect	cam_ori;
	t_vect	world_up;
	t_vect	right;
	t_vect	up;

	cam_ori = mlxs->sc->cam.norm;
	world_up = vect(0, 1, 0);
	right = normalize(cross_product(cam_ori, world_up));
	up = normalize(cross_product(right, cam_ori));
	if (keycode == XK_KP_Left)
		mlxs->sc->cam.norm = rotate_around_axis(cam_ori, up, -10);
	else if (keycode == XK_KP_Right)
		mlxs->sc->cam.norm = rotate_around_axis(cam_ori, up, 10);
	else if (keycode == XK_KP_Up || keycode == XK_KP_Down)
		kb_event_handler_rotate_cam_updown(keycode, mlxs, right);
}

void	kb_event_handler_translate_cam(int keycode, t_mlxs *mlxs)
{
	t_vect	translation_vect;

	translation_vect = vect(0, 0, 0);
	if (keycode == XK_w)
		translation_vect = vect(0, -1, 0);
	else if (keycode == XK_a)
		translation_vect = vect(-1, 0, 0);
	else if (keycode == XK_s)
		translation_vect = vect(0, 1, 0);
	else if (keycode == XK_d)
		translation_vect = vect(1, 0, 0);
	else if (keycode == XK_Up)
		translation_vect = vect(0, 0, 1);
	else if (keycode == XK_Down)
		translation_vect = vect(0, 0, -1);
	translation_vect = rotate_vector(translation_vect, mlxs->sc->cam.norm);
	mlxs->sc->cam.pos = add(mlxs->sc->cam.pos, translation_vect);
}

void	kb_event_handler_zoom_cam(int keycode, t_mlxs *mlxs)
{
	double	diff;

	diff = 0;
	if (keycode == XK_KP_Add && mlxs->sc->cam.fov_deg < 179)
		diff = 1;
	else if (keycode == XK_KP_Subtract && mlxs->sc->cam.fov_deg > 2)
		diff = -1;
	mlxs->sc->cam.fov_deg += diff;
}

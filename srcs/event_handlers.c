/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 05:01:26 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 02:59:18 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "mlx_structs.h"
#include "generic_obj.h"
#include <math.h>
#include <X11/keysym.h>

void	mouse_event_handler_resize_obj(int button, t_mlxs *mlxs)
{
	double	diff;

	diff = 0;
	if (button == MOUSE_SCROLL_UP)
		diff = 1;
	else if (button == MOUSE_SCROLL_DOWN)
		diff = -1;
	resize_obj_1(mlxs->last_selected_obj, diff);
}

void	kb_event_handler_transform_obj(int keycode, t_mlxs *mlxs)
{
	if (keycode == XK_KP_Add || keycode == XK_KP_Subtract)
		kb_event_handler_resize_obj(keycode, mlxs);
	else if (keycode == XK_w || keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_Up || keycode == XK_Down)
		kb_event_handler_translate_obj(keycode, mlxs);
	else if (keycode == XK_KP_Left || keycode == XK_KP_Right
		|| keycode == XK_KP_Up || keycode == XK_KP_Down)
		kb_event_handler_rotate_obj(keycode, mlxs);
	else
		return ;
	render(mlxs);
}

void	kb_event_handler_rotate_obj(int keycode, t_mlxs *mlxs)
{
	t_vect	target_z;

	target_z = vect(0, 0, 1);
	if (keycode == XK_KP_Left)
		target_z = vect(-0.6, 0, 0.8);
	else if (keycode == XK_KP_Right)
		target_z = vect(0.6, 0, 0.8);
	else if (keycode == XK_KP_Up)
		target_z = vect(0, 0.6, 0.8);
	else if (keycode == XK_KP_Down)
		target_z = vect(0, -0.6, 0.8);
	rotate_obj(mlxs->last_selected_obj, target_z);
}

void	kb_event_handler_translate_obj(int keycode, t_mlxs *mlxs)
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
	translate_obj(mlxs->last_selected_obj, translation_vect);
}

void	kb_event_handler_resize_obj(int keycode, t_mlxs *mlxs)
{
	double	diff;

	diff = 0;
	if (keycode == XK_KP_Add)
		diff = 1;
	else if (keycode == XK_KP_Subtract)
		diff = -1;
	resize_obj_2(mlxs->last_selected_obj, diff);
}

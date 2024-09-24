/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:26:36 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/24 09:44:48 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "mlx_structs.h"
#include <math.h>
#include <X11/keysym.h>

void	kb_event_handler_adjust_light(int keycode, t_mlxs *mlxs)
{
	if (keycode == XK_KP_Add || keycode == XK_KP_Subtract)
		kb_event_handler_adjust_light_ratio(keycode, mlxs);
	else if (keycode == XK_w || keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_Up || keycode == XK_Down)
		kb_event_handler_translate_light(keycode, mlxs);
}

void	kb_event_handler_adjust_light_ratio(int keycode, t_mlxs *mlxs)
{
	double	diff;

	diff = 0;
	if (keycode == XK_KP_Add)
		diff = 0.1;
	else if (keycode == XK_KP_Subtract)
		diff = -0.1;
	mlxs->sc->light.ratio += diff;
	if (mlxs->sc->light.ratio > 1)
		mlxs->sc->light.ratio = 1;
	else if (mlxs->sc->light.ratio < 0)
		mlxs->sc->light.ratio = 0;
}

void	kb_event_handler_translate_light(int keycode, t_mlxs *mlxs)
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
	mlxs->sc->light.pos = add(mlxs->sc->light.pos, translation_vect);
}

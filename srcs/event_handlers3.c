/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:26:36 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/26 00:15:02 by tjien-ji         ###   ########.fr       */
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
	else
		return ;
	render(mlxs);
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
		translation_vect = mult(mlxs->sc->cam.v, -1);
	else if (keycode == XK_a)
		translation_vect = mult(mlxs->sc->cam.u, -1);
	else if (keycode == XK_s)
		translation_vect = mlxs->sc->cam.v;
	else if (keycode == XK_d)
		translation_vect = mlxs->sc->cam.u;
	else if (keycode == XK_Up)
		translation_vect = mlxs->sc->cam.norm;
	else if (keycode == XK_Down)
		translation_vect = mult(mlxs->sc->cam.norm, -1);
	mlxs->sc->light.pos = add(mlxs->sc->light.pos, translation_vect);
}

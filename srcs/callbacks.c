/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 05:54:25 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/24 09:38:03 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "mlx.h"
#include "generic_obj.h"
#include <math.h>
#include <X11/keysym.h>

int	mouse_hook_callback(int button, int x, int y, void *param)
{
	t_mlxs	*mlxs;

	mlxs = (t_mlxs *)param;
	if (button == LEFT_MOUSE_BUTTON)
		mlxs->last_selected_obj = mlxs->arr_obj_ptrs[(WIN_W * y) + x];
	else if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		mouse_event_handler_resize_obj(button, mlxs);
		render(mlxs);
	}
	return (0);
}

int	kb_hook_callback(int keycode, void *param)
{
	t_mlxs	*mlxs;

	mlxs = (t_mlxs *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(mlxs->mlx);
	else if (keycode == XK_q)
		mlxs->last_selected_obj = NULL;
	else if (keycode == XK_l)
		mlxs->last_selected_obj = &mlxs->sc->light;
	else if (keycode == XK_KP_Add || keycode == XK_KP_Subtract
		|| keycode == XK_w || keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_Up || keycode == XK_Down
		|| keycode == XK_KP_Left || keycode == XK_KP_Right
		|| keycode == XK_KP_Up || keycode == XK_KP_Down)
	{
		if (mlxs->last_selected_obj == &mlxs->sc->light)
			kb_event_handler_adjust_light(keycode, mlxs);
		else if (mlxs->last_selected_obj != NULL)
			kb_event_handler_transform_obj(keycode, mlxs);
		else
			kb_event_handler_transform_cam(keycode, mlxs);
		render(mlxs);
	}
	return (0);
}

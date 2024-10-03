/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 05:54:25 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/25 19:30:11 by jyap             ###   ########.fr       */
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
	{
		mlxs->last_selected_obj = mlxs->arr_obj_ptrs[(WIN_W * y) + x];
		print_controls(mlxs);
	}
	else if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		mouse_event_handler_resize_obj(button, mlxs);
	return (0);
}

bool	check_keycode(int keycode)
{
	return (keycode == XK_KP_Add || keycode == XK_KP_Subtract
		|| keycode == XK_w || keycode == XK_a || keycode == XK_s
		|| keycode == XK_d || keycode == XK_Up || keycode == XK_Down
		|| keycode == XK_KP_Left || keycode == XK_KP_Right
		|| keycode == XK_KP_Up || keycode == XK_KP_Down
		|| keycode == XK_bracketleft || keycode == XK_bracketright);
}

void	select_last_obj(t_mlxs *mlxs, int keycode)
{
	if (keycode == XK_l)
		mlxs->last_selected_obj = &mlxs->sc->light;
	else
		mlxs->last_selected_obj = NULL;
	print_controls(mlxs);
}

int	kb_hook_callback(int keycode, void *param)
{
	t_mlxs	*mlxs;

	mlxs = (t_mlxs *)param;
	if (keycode == XK_Escape)
	{
		mlx_loop_end(mlxs->mlx);
		printf("\033[2J\033[H");
	}
	else if (keycode == XK_q || keycode == XK_l)
		select_last_obj(mlxs, keycode);
	else if (check_keycode(keycode))
	{
		if (mlxs->last_selected_obj == &mlxs->sc->light)
			kb_event_handler_adjust_light(keycode, mlxs);
		else if (mlxs->last_selected_obj != NULL)
			kb_event_handler_transform_obj(keycode, mlxs);
		else
			kb_event_handler_transform_cam(keycode, mlxs);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:44:29 by jyap              #+#    #+#             */
/*   Updated: 2024/09/25 16:38:50 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_mode(void)
{
	printf("Controls\n");
	printf("=========\n\n");
	printf("  Camera      Light       Quit\n\n");
	printf("╔═══════╗   ╔═══════╗   ╔═══════╗\n");
	printf("║       ║   ║       ║   ║       ║\n");
	printf("║   Q   ║   ║   L   ║   ║  Esc  ║\n");
	printf("║       ║   ║       ║   ║       ║\n");
	printf("╚═══════╝   ╚═══════╝   ╚═══════╝\n\n");
}

void	print_transform(void)
{
	printf("        Translate                     Rotate\n\n");
	printf("╔═══════╦═══════╦═══════╗    ╔═══════╦═══════╦═══════╗\n");
	printf("║   ↑   ║   W   ║   ↓   ║    ║   [   ║   8   ║   ]   ║\n");
	printf("║  +z   ║   Up  ║  -z   ║    ║   z←  ║   x↑  ║   z→  ║\n");
	printf("╠═══════╬═══════╬═══════╣    ╠═══════╬═══════╬═══════╣\n");
	printf("║   A   ║   S   ║   D   ║    ║   4   ║   2   ║   6   ║\n");
	printf("║  Left ║  Down ║ Right ║    ║   y←  ║   x↓  ║   y→  ║\n");
	printf("╚═══════╩═══════╩═══════╝    ╚═══════╩═══════╩═══════╝\n\n");
}

void	print_signs(void)
{
	printf("╔═══════╦═══════╗\n");
	printf("║       ║       ║\n");
	printf("║   +   ║   -   ║\n");
	printf("║       ║       ║\n");
	printf("╚═══════╩═══════╝\n\n");
}

void	print_light_controls(t_light l)
{
	print_mode();
	print_transform();
	printf("Set Light Brightness Ratio\n\n");
	print_signs();
	printf("Currently selected : Light\n");
	printf("--------------------------\n\n");
	printf("Coordinates :(%.3f, %.3f, %.3f)\n\n",
		l.pos.x, l.pos.y, l.pos.z);
	printf("Light Brightness Ratio : %.2f\n", l.ratio);
}

void	print_cam_controls(t_camera c)
{
	print_mode();
	print_transform();
	printf("Zoom\n\n");
	print_signs();
	printf("Currently selected : Camera\n");
	printf("---------------------------\n\n");
	printf("Coordinates :(%.3f, %.3f, %.3f)\n\n",
		c.pos.x, c.pos.y, c.pos.z);
	printf("Camera Orientation :(%.3f, %.3f, %.3f)\n\n",
		c.norm.x, c.norm.y, c.norm.z);
	printf("FOV :%d\n", (int)c.fov_deg);
}

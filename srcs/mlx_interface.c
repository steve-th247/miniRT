#include "mlx_structs.h"

#ifndef WIN_W
# define WIN_W 500
#endif

#ifndef WIN_H
# define WIN_H 500
#endif


void	set_img_pixel_color(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = img.addr + (y * img.line_length + \
		x * (img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

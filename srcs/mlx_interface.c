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
		if (img.endian)
		{
			color = ((color >> 24) & 0xff)
				| ((color >> 8) & 0xff00)
				| ((color << 8) & 0xff0000)
				| ((color << 24) & 0xff000000);
		}
		*(unsigned int *)dst = color;
	}
}

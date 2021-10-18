#include "fdf.h"

void	isometric(t_pixel *i, t_img *img)
{
	i->x = (i->x - i->y) * cos(img->angle);
	i->y = (i->x + i->y) * sin(img->angle) - i->z;
}

//Makes rendering more efficient but messes up the edges.
//if (x <= 1000 && x >= 0 && y <= 1000 && y >= 0 
//&& x1 <= 1000 && x1 >= 0 && y1 <= 1000 && y1 >= 0)

void	bresenham(t_pixel a, t_pixel b, t_img *img)
{
	float	x_step;
	float	y_step;
	int		max;

	a.z = img->map[(int)a.y][(int)a.x] * img->z_multy * (img->zoom / 10);
	b.z = img->map[(int)b.y][(int)b.x] * img->z_multy * (img->zoom / 10);
	zoom(&a, &b, img);
	isometric(&a, img);
	isometric(&b, img);
	shift(&a, &b, img);
	color(a.z, b.z, img);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = biggest(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(img->mlx_ptr, img->win_ptr, a.x, a.y, img->color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	draw(t_img *img)
{
	t_pixel	a;
	t_pixel	b;

	a.y = 0;
	while (a.y < img->height)
	{
		a.x = 0;
		while (a.x < img->width)
		{
			if (a.x < img->width - 1)
			{
				b.x = a.x + 1;
				b.y = a.y;
				bresenham(a, b, img);
			}
			if (a.y < img->height - 1)
			{
				b.x = a.x;
				b.y = a.y + 1;
				bresenham(a, b, img);
			}	
			a.x++;
		}
		a.y++;
	}
}

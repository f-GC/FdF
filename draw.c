/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:59:32 by fgarcia-          #+#    #+#             */
/*   Updated: 2021/10/25 18:59:33 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	float	max;

	set_color(a, b, img);
	a.z = img->map[(int)a.y][(int)a.x].z * img->z_multy * (img->zoom / 10);
	b.z = img->map[(int)b.y][(int)b.x].z * img->z_multy * (img->zoom / 10);
	zoom(&a, &b, img);
	isometric(&a, img);
	isometric(&b, img);
	shift(&a, &b, img);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = biggest(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		my_mlx_pixel_put(img, a.x, a.y, img->color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	draw2(t_pixel *a, t_pixel *b, t_img *img, int flag)
{
	if (flag == 1)
	{
		b->x = a->x + 1;
		b->y = a->y;
		bresenham(*a, *b, img);
	}
	if (flag == 0)
	{
		b->x = a->x;
		b->y = a->y + 1;
		bresenham(*a, *b, img);
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
				draw2(&a, &b, img, 1);
			if (a.y < img->height - 1)
				draw2(&a, &b, img, 0);
			a.x++;
		}
		a.y++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

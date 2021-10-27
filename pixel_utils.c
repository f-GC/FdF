/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:59:47 by fgarcia-          #+#    #+#             */
/*   Updated: 2021/10/25 18:59:48 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_pixel *a, t_pixel *b, t_img *img)
{
	a->x *= img->zoom;
	a->y *= img->zoom;
	b->x *= img->zoom;
	b->y *= img->zoom;
}

void	shift(t_pixel *a, t_pixel *b, t_img *img)
{
	a->x += img->x_shift;
	a->y += img->y_shift;
	b->x += img->x_shift;
	b->y += img->y_shift;
}

void	set_color(t_pixel a, t_pixel b, t_img *img)
{
	if (img->map[(int)b.y][(int)b.x].z < img->map[(int)a.y][(int)a.x].color)
		img->color = img->map[(int)a.y][(int)a.x].color;
	else
		img->color = img->map[(int)b.y][(int)b.x].color;
}

int	biggest(float x_step, float y_step)
{
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < 1500 && y >= 0 && y < 1000)
	{
		i = (x * img->bits_per_pixel / 8) + (y * img->line_length);
		img->addr[i] = color;
		img->addr[++i] = color >> 8;
		img->addr[++i] = color >> 16;
	}
}

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

void	color(float z, float z1, t_img *img)
{
	if (z || z1)
		img->color = 0xe80c0c;
	else
		img->color = 0xffffff;
}

int	biggest(float x_step, float y_step)
{
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:59:25 by fgarcia-          #+#    #+#             */
/*   Updated: 2021/10/25 18:59:28 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	str_hex(const char *str)
{
	int		res;
	char	c;
	char	v;

	res = 0;
	c = *str++;
	while (c)
	{
		v = ((c & 0xF) + (c >> 6)) | ((c >> 3) & 0x8);
		res = (res << 4) | (int) v;
		c = *str++;
	}
	return (res);
}

//For Linux

int	valid_key(int key)
{
	if (key == 'q' || key == 'e' || key == 'w' || key == 'a'
		|| key == 's' || key == 'd' || key == 'r' || key == 'f'
		|| key == 65307 || key == 't' || key == 'g')
		return (1);
	else
		return (0);
}

void	zoom_value(t_img *img, char key)
{
	if (key == 'e')
	{
		if (img->zoom > 2)
		{
			if (img->zoom > 5)
				img->zoom -= 5;
			if (img->zoom <= 5)
				img->zoom -= 1;
		}
	}
	if (key == 'q')
	{
		if (img->zoom <= 40)
		{
			if (img->zoom >= 5)
				img->zoom += 5;
			if (img->zoom < 5)
				img->zoom += 1;
		}
	}
}

void	key_action(int key, t_img *img)
{
	if (key == 'q')
		zoom_value(img, 'q');
	if (key == 'e')
		zoom_value(img, 'e');
	if (key == 's')
		img->y_shift -= 20;
	if (key == 'a')
		img->x_shift += 20;
	if (key == 'w')
		img->y_shift += 20;
	if (key == 'd')
		img->x_shift -= 20;
	if (key == 'r')
		img->angle -= 0.01;
	if (key == 'f')
		img->angle += 0.01;
	if (key == 65307)
		appout(img, 1);
	if (key == 't')
		img->z_multy += 0.5;
	if (key == 'g')
		img->z_multy -= 0.5;
}

// For MAC
/*
int	valid_key(int key)
{
	if (key == 12 || key == 14 || key == 1 || key == 0
		|| key == 13 || key == 2 || key == 15 || key == 3
		|| key == 53 || key == 17 || key == 5)
		return (1);
	else
		return (0);
}

void	zoom_value(t_img *img, int key)
{
	if (key == 14)
	{
		if (img->zoom > 2)
		{
			if (img->zoom > 5)
				img->zoom -= 5;
			if (img->zoom <= 5)
				img->zoom -= 1;
		}
	}
	if (key == 12)
	{
		if (img->zoom >= 5)
			img->zoom += 5;
		if (img->zoom < 5)
			img->zoom += 1;
	}
}

void	key_action(int key, t_img *img)
{
	if (key == 12)
		zoom_value(img, 12);
	if (key == 14)
		zoom_value(img, 14);
	if (key == 1)
		img->y_shift -= 20;
	if (key == 0)
		img->x_shift += 20;
	if (key == 13)
		img->y_shift += 20;
	if (key == 2)
		img->x_shift -= 20;
	if (key == 15)
		img->angle -= 0.01;
	if (key == 3)
		img->angle += 0.01;
	if (key == 53)
		appout(img, 1);
	if (key == 17)
		img->z_multy += 0.5;
	if (key == 5)
		img->z_multy -= 0.5;
}
*/
int	deal_key(int key, t_img *img)
{
	if (valid_key(key))
	{
		key_action(key, img);
		mlx_destroy_image(img->mlx_ptr, img->img);
		img->img = NULL;
		init_frame(img);
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
		draw(img);
		draw_menu(img);
	}
	return (0);
}

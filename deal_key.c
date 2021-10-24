#include "fdf.h"

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
		if (img->zoom >= 5)
			img->zoom += 5;
		if (img->zoom < 5)
			img->zoom += 1;
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

int	deal_key(int key, t_img *img)
{
	if (valid_key(key))
	{
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
		key_action(key, img);
		draw(img);
		draw_menu(img);
	}
	return (0);
}

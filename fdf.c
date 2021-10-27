/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:59:36 by fgarcia-          #+#    #+#             */
/*   Updated: 2021/10/25 18:59:37 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	appout(t_img *img, int flag)
{
	int	i;

	if (flag == 0)
		write(2, "Error reading file.\n", 21);
	else
	{
		i = 0;
		while (i < img->height)
		{
			free(img->map[i]);
			i++;
		}
		free(img->map);
		if (img->img != NULL)
			mlx_destroy_image(img->mlx_ptr, img->img);
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	}
	free(img);
	exit(0);
}

void	init_frame(t_img *img)
{
	img->img = mlx_new_image(img->mlx_ptr, 1500, 1000);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	init_img(t_img *img, char *file_name)
{
	read_file(file_name, img);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1500, 1000, "FdF");
	init_frame(img);
	img->zoom = 25;
	img->x_shift = 750;
	img->y_shift = 150;
	img->angle = 0.8;
	img->z_multy = 1;
}

int	main(int argc, char **argv)
{
	t_img	*img;

	if (argc != 2)
	{
		write(2, "Usage: ./fdf \"map_file\".fdf\n", 29);
		return (0);
	}
	img = malloc(sizeof(t_img));
	init_img(img, argv[1]);
	draw(img);
	draw_menu(img);
	mlx_key_hook(img->win_ptr, deal_key, img);
	mlx_loop(img->mlx_ptr);
	appout(img, 1);
}

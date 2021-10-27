/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:59:40 by fgarcia-          #+#    #+#             */
/*   Updated: 2021/10/25 18:59:41 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct value
{
	float	z;
	int		color;
}			t_val;

typedef struct image
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	zoom;
	int		height;
	int		width;
	t_val	**map;
	int		color;
	int		x_shift;
	int		y_shift;
	float	z_multy;
	float	angle;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct pixel
{
	float	x;
	float	y;
	float	z;
}			t_pixel;

void	read_file(char *file_name, t_img *img);
void	bresenham(t_pixel a, t_pixel b, t_img *img);
void	draw(t_img *img);
int		deal_key(int key, t_img *img);
void	draw_menu(t_img *img);
void	appout(t_img *img, int flag);
void	zoom(t_pixel *a, t_pixel *b, t_img *img);
void	shift(t_pixel *a, t_pixel *b, t_img *img);
void	set_color(t_pixel a, t_pixel b, t_img *img);
int		biggest(float x_step, float y_step);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_frame(t_img *img);
int		str_hex(const char *str);

#endif
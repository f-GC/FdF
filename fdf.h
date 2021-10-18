#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct image
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	zoom;
	int		height;
	int		width;
	int		**map;
	int		color;
	int		x_shift;
	int		y_shift;
	float	z_multy;
	float	angle;
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
void	color(float z, float z1, t_img *img);
int		biggest(float x_step, float y_step);

#endif
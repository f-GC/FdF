#include "fdf.h"

void	draw_menu(t_img *img)
{
	char	*menu;

	menu = "Use W, A, S, D to move picture.";
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 10, 0x03fc35, menu);
	menu = "Use Q, E to zoom in/out.";
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 25, 0x03fc35, menu);
	menu = "Use R, F to change proyection angle.";
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 40, 0x03fc35, menu);
	menu = "Use T, G to exagerate Z axis.";
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 55, 0x03fc35, menu);
	menu = "Use ESC to exit.";
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 70, 0x03fc35, menu);
}

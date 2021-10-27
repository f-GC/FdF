/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:59:52 by fgarcia-          #+#    #+#             */
/*   Updated: 2021/10/25 18:59:53 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
		line = NULL;
	}
	if (line != NULL)
		free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	line = NULL;
	close(fd);
	return (width);
}

void	extract_map(t_val *map_line, char *line)
{
	char	**nums;
	int		i;
	char	**color;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		if (ft_wdcounter(nums[i], ',') == 2)
		{
			color = ft_split(nums[i], ',');
			map_line[i].color = str_hex(&color[1][2]);
			free(color[0]);
			free(color[1]);
			free(color);
		}
		else
			map_line[i].color = 0xffffff;
		map_line[i].z = ft_atoi(nums[i]);
		free(nums[i]);
		nums[i] = NULL;
		i++;
	}
	free(nums);
}

void	alloc_map(t_img *img)
{
	int	i;

	i = 0;
	img->map = malloc(sizeof(t_val *) * (img->height));
	while (i < img->height)
	{
		img->map[i] = malloc(sizeof(t_val) * (img->width));
		i++;
	}
}

void	read_file(char *file_name, t_img *img)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		appout(img, 0);
	img->height = get_height(file_name);
	img->width = get_width(file_name);
	alloc_map(img);
	i = 0;
	while (get_next_line(fd, &line))
	{
		extract_map(img->map[i], line);
		free(line);
		line = NULL;
		i++;
	}
	if (line != NULL)
		free(line);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:23:25 by fgarcia-          #+#    #+#             */
/*   Updated: 2019/12/20 12:14:31 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_check(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
	{
		if (str[cont] == '\n')
			return (1);
		cont++;
	}
	return (0);
}

int	return_func(char **out, char **line, int rc)
{
	char	*tmp;
	int		len;

	len = 0;
	if (rc < 0)
		return (-1);
	while ((*out)[len] != '\n' && (*out)[len] != '\0')
		len++;
	if ((*out)[len] == '\n')
	{
		*line = ft_substr(*out, 0, len);
		tmp = ft_strdup(&(*out)[len + 1]);
		free(*out);
		*out = tmp;
	}
	else
	{
		*line = ft_strdup(*out);
		ft_strdel(out);
	}
	if (rc == 0 && *out == NULL)
		return (0);
	return (1);
}

int	out_of_lines(char **line)
{
	*line = ft_strdup("");
	return (0);
}

void	get_next_line2(int *rc, int fd, char **out, char *buffer)
{
	char	*tmp;

	*rc = read(fd, buffer, BUFFER_SIZE);
	while (*rc > 0)
	{
		buffer[*rc] = '\0';
		if (out[fd] == NULL)
			out[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(out[fd], buffer);
			free(out[fd]);
			out[fd] = tmp;
		}
		if (nl_check(out[fd]))
			break ;
		*rc = read(fd, buffer, BUFFER_SIZE);
	}
}

int	get_next_line(int fd, char **line)
{
	int			rc;
	char		buffer[BUFFER_SIZE + 1];
	static char	*out[FD_SIZE];

	if (fd < 0 || line == NULL)
		return (-1);
	get_next_line2(&rc, fd, out, buffer);
	if (rc == 0 && out[fd] == NULL)
		return (out_of_lines(line));
	else
		return (return_func(&out[fd], line, rc));
}

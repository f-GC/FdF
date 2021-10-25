/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia- <fgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:59:09 by fgarcia-          #+#    #+#             */
/*   Updated: 2019/11/11 21:00:49 by fgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) + 1;
	str = malloc(len);
	if (!(str))
		return (0);
	ft_strlcpy(str, s1, len);
	return (str);
}

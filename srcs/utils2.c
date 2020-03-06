/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:31:35 by pnielly           #+#    #+#             */
/*   Updated: 2020/03/05 22:39:54 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_fill_line(char *line, char c, int len)
{
	int		i;
	int		len_line;
	char	*dst;

	len_line = ft_strlen(line);
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i <= len_line)
		dst[i] = line[i];
	i--;
	while (i <= len)
		dst[i++] = c;
	dst[i] = '\0';
	return (dst);
}

char	ft_first_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	return (line[i]);
}

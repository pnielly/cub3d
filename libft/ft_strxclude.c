/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxclude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:22:40 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/15 16:19:12 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strxclude(char *s, char *set)
{
	int	i;
	int	len_dest;
	char	*dest;

	i = -1;
	len_dest = 0;
	while (s[++i])
		if (!ft_set(s[i], set))
			len_dest++;
	if (!(dest = malloc(sizeof(char) * (len_dest + 1))))
		return (0);
	i = -1;
	len_dest = -1;
	while (s[++i])
		if (!ft_set(s[i], set))
			dest[++len_dest] = s[i];
	dest[len_dest + 1] = '\0';
	return (dest);
}

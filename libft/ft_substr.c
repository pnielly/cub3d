/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:26:08 by pnielly           #+#    #+#             */
/*   Updated: 2019/10/24 13:05:59 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	j = start;
	i = 0;
	while (len-- > 0 && s[j] != 0)
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

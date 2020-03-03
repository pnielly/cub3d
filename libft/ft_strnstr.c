/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:43:29 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/15 15:59:44 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int		i;
	unsigned int		j;

	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] != needle[0] && haystack[i] != '\0' && i < len)
			i++;
		while (haystack[i] == needle[j] && j < len && i < len && needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0' || j == len)
		{
			haystack = &haystack[i - j];
			return ((char*)haystack);
		}
	}
	return (NULL);
}

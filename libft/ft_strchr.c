/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:37 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/27 11:01:07 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s || !c)
		return (ptr);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		ptr = (char *)s + i;
	return (ptr);
}

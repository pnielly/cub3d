/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:46:47 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/28 14:10:13 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1) + 1;
	if (!(dest = (char*)malloc(sizeof(char) * len)))
		return ((char *)0);
	return ((char *)ft_memcpy(dest, s1, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:59:43 by pnielly           #+#    #+#             */
/*   Updated: 2019/10/20 17:09:48 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*p;
	unsigned int	i;

	p = (const char *)s;
	if (!n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (p[i] == c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}

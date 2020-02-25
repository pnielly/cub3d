/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:47 by pnielly           #+#    #+#             */
/*   Updated: 2020/02/10 16:37:05 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s1;
	unsigned char		*d1;

	if (!src && !dst)
		return (0);
	s1 = src;
	d1 = dst;
	if (!n)
		return (dst);
	while (n-- > 0)
		*d1++ = *s1++;
	return (dst);
}

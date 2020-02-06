/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:26:41 by pnielly           #+#    #+#             */
/*   Updated: 2019/10/24 13:14:44 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	i;

	i = 0;
	p = (char*)malloc(size * count);
	if (!(p))
		return (0);
	while (i < count * size)
		p[i++] = 0;
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:29:52 by pnielly           #+#    #+#             */
/*   Updated: 2019/10/24 12:43:43 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_len(int n)
{
	int		i;
	int		m;

	i = 0;
	m = n;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	if (m < 0)
		i++;
	return (i);
}

char		*ft_build_str(int n, char *str, int len)
{
	long	v;
	int		k;

	if (n == 0)
	{
		str[0] = 48;
	}
	v = (long)n;
	if (v < 0)
	{
		str[0] = '-';
		v = -v;
	}
	str[len] = '\0';
	if (v != 0)
	{
		k = (1 - (n / v)) / 2;
		while (len > k)
		{
			str[--len] = v % 10 + 48;
			v = v / 10;
		}
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	if (!(str = malloc(len + 1)))
		return (0);
	return (ft_build_str(n, str, len));
}

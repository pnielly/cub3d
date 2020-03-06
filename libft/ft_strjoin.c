/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:40:56 by pnielly           #+#    #+#             */
/*   Updated: 2019/10/23 17:37:21 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = (char*)malloc(sizeof(char) * i + sizeof(char) * j + 1)))
		return (0);
	while (++k < i)
		str[k] = s1[k];
	while (k < i + j)
	{
		str[k] = s2[k - i];
		k++;
	}
	str[k] = '\0';
	return (str);
}

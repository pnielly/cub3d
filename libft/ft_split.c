/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:31:36 by pnielly           #+#    #+#             */
/*   Updated: 2019/10/24 13:16:51 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_box(char const *str, char c)
{
	int	i;
	int	k;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		k = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (k != i)
			count++;
	}
	return (count);
}

int			size_box(char const *str, int position, char c)
{
	int	letter;
	int	i;

	i = 0;
	while (position >= 0)
	{
		letter = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			letter++;
		}
		position--;
	}
	return (letter);
}

int			borne_box(char const *str, int position, char c)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] && position >= 0)
	{
		while (str[i] == c)
			i++;
		k = 0;
		while (str[i] != c && str[i] != '\0')
		{
			k++;
			i++;
		}
		position--;
	}
	return (i - k);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		position;
	int		letter;
	int		i;

	if (!s || !(tab = (char**)malloc(sizeof(char*) * ((count_box(s, c) + 1)))))
		return (NULL);
	position = -1;
	while (++position < count_box(s, c))
	{
		if (!(tab[position] = (char*)malloc(sizeof(char)
						* (size_box(s, position, c) + 1))))
			return (NULL);
		letter = 0;
		i = borne_box(s, position, c);
		while (s[i] != c && s[i] != '\0')
		{
			tab[position][letter] = (char)s[i];
			letter++;
			i++;
		}
		tab[position][letter] = '\0';
	}
	tab[position] = NULL;
	return ((char**)tab);
}

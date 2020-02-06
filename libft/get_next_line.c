/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:28:47 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/29 19:27:42 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
char			*ft_substr(char const *s, unsigned long start, size_t len)
{
	char			*dest;
	unsigned long	i;
	unsigned long	j;

	if (!s)
		return (NULL);
	if (!(dest = malloc(len + 1)))
		return (0);
	if (start > ft_strlen(s))
	{
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	j = start;
	while (len-- > 0 && s[j] != '\0')
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
**/
int				endfile_or_error(char *curr, char **line, int fd)
{
	char		buf[BUFFER_SIZE + 1];

	if (read(fd, buf, BUFFER_SIZE) == 0)
	{
		if (curr)
		{
			*line = ft_strdup(curr);
			free(curr);
		}
		else
			*line = ft_strdup("");
		return (0);
	}
	return (-1);
}

char			*clean_stock(char *stock)
{
	stock = ft_strdup("");
	free(stock);
	stock = NULL;
	return (stock);
}

char			*get_curr(char *stock, int fd)
{
	long		ret;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	ret = 1;
	while (!(ft_strnstr(stock, "\n", ft_strlen(stock))) && ret)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1 || fd < 0)
			return (NULL);
		if (!ret)
			break ;
		buf[ret] = '\0';
		tmp = ft_strjoin(stock, buf);
		free(stock);
		stock = tmp;
	}
	return (stock);
}

int				get_next_line(int fd, char **line)
{
	static char		*stock = NULL;
	char			*curr;
	long			i;

	if (stock == NULL)
		stock = ft_strdup("");
	if (!(ft_strnstr(stock, "\n", ft_strlen(stock))))
	{
		curr = get_curr(stock, fd);
		if (!curr || !ft_strnstr(curr, "\n", ft_strlen(curr)))
		{
			stock = clean_stock(stock);
			return (endfile_or_error(curr, line, fd));
		}
	}
	else
		curr = stock;
	i = 0;
	while (curr[i] != '\n' && curr[i])
		i++;
	stock = ft_substr(curr, i + 1, ft_strlen(curr) - i + 1);
	curr[i] = '\0';
	*line = ft_strdup(curr);
	free(curr);
	return (1);
}

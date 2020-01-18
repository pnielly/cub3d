/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:27:18 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/15 20:44:33 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	display(int n, int fd)
{
	if (n / 10 != 0)
		display(n / 10, fd);
	ft_putchar_fd('0' - (n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	else
		n = -n;
	display(n, fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:04:33 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/16 11:53:20 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cub3d.h"

int	ft_file_extsn(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] != '.' && file_name[i])
		i++;
	file_name += i;
	return (ft_strncmp(file_name, ".cub", 4));
}

int	main(int argc, char **argv)
{
	t_stock	*stock;

	if (!(stock = malloc(sizeof(t_stock))))
		return (ft_putstr("MALLOC FAILED"));
	if (argc == 1 || ft_file_extsn(argv[1]))
		return (ft_putstr("MISSING MAP (should be 1st arg and '*.cub')"));
	if (argc > 3 || (argc == 3 && ft_strncmp(argv[2], "-save", 5)))
		return (ft_putstr("TOO MANY ARGUMENTS !"));
	if (ft_check_map(stock, argv[1]))
		return (ft_putstr("WRONG MAP SETTING"));
	if (ft_parsing(stock))
		return (ft_putstr("PARSING FAILED"));
	if (ft_init_game(stock))
		return (ft_putstr("ENV CAN'T BE INIT FOR SOME REASON"));
/**	ft_events(); **/
	return (0);
}

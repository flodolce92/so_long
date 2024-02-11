/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 07:58:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/09 15:05:40 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	game;
	int		i;
	i = 0;
	if (ac < 2)
	{
		ft_putstr_fd("Too few parameters.\n", STDOUT_FILENO);
		return (1);
	}
	(void)game;
	get_rows(&game, av[1]);
	// printf("Map rows: %d\n", game.rows);
	fill_map(&game, av[1]);
	printf("Map cols: %d\n", game.cols);
	// while (game.map[i] != NULL)
	// {
	// 	printf("Map line %d:\t%s", i, game.map[i]);
	// 	i++;
	// }
	check_map(&game);
	return (0);
}

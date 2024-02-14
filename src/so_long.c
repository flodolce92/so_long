/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 07:58:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/14 19:38:01 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_window(t_data *game)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (i < (*game).rows)
	{
		j = 0;
		x = 0;
		while (j < (*game).cols)
		{
			if ((*game).map[i][j] == '1')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0x000000, "1");
			else if ((*game).map[i][j] == '0')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0xFFFFFF, "0");
			else if ((*game).map[i][j] == 'P')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0x00FF00, "P");
			else if ((*game).map[i][j] == 'E')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0xFF0000, "E");
			else if ((*game).map[i][j] == 'C')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0x0000FF, "C");
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}

void	create_window(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed.\n", STDOUT_FILENO);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx,
				game->cols * 32,
				game->rows * 32,
				"so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: mlx_new_window failed.\n", STDOUT_FILENO);
		exit(1);
	}
	fill_window(game);
}

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
	// printf("Map cols: %d\n", game.cols);
	// while (game.map[i] != NULL)
	// {
	// 	printf("Map line %d:\t%s", i, game.map[i]);
	// 	i++;
	// }
	check_map(&game);
	create_window(&game);
	mlx_loop(game.mlx);
	exit(0);
	return (0);
}

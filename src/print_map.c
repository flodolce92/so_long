/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:46:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/03 05:17:12 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char *line, t_data *game, int row)
{
	int	column;

	column = 0;
	while (line[column])
	{
		if (line[column] == '1')
			print_wall(game, column, row);
		else if (line[column] == '0')
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, column * TILE_SIZE, (row * TILE_SIZE));
		else if (line[column] == 'C')
			print_coin(game, column, row);
		else if (line[column] == 'E')
			print_exit(game, column, row);
		else if (line[column] == 'P')
			print_player(game, column, row);
		else if (line[column] == 'B')
			print_bug(game, column, row);
		column++;
	}
}

void	fill_window(t_data *game)
{
	int		i;
	char	*moves;
	char	*score;

	i = 0;
	moves = ft_itoa(game->moves);
	score = ft_itoa(game->score);
	while (game->map[i] != NULL)
	{
		print_map(game->map[i], game, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.moves, TILE_SIZE, ((game->rows - 1) * TILE_SIZE) + 32);
	mlx_string_put(game->mlx, game->win, TILE_SIZE + 40, \
		(game->rows * TILE_SIZE) - 10, 0x00000000, moves);
	mlx_string_put(game->mlx, game->win, TILE_SIZE * 2, \
		(game->rows * TILE_SIZE) - 10, 0x00000000, "PROJECTS: ");
	mlx_string_put(game->mlx, game->win, (TILE_SIZE * 2) + 1, \
		(game->rows * TILE_SIZE) - 10, 0x00000000, "PROJECTS: ");
	mlx_string_put(game->mlx, game->win, (TILE_SIZE * 3) + 10, \
		(game->rows * TILE_SIZE) - 10, 0x00000000, score);
	free(moves);
	free(score);
}

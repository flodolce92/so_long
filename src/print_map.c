/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:46:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/09 02:26:29 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char *line, t_data *game, int index)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			print_wall(game, i, index);
		else if (line[i] == '0')
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
		else if (line[i] == 'C')
			print_coin(game, i, index);
		else if (line[i] == 'E')
			print_exit(game, i, index);
		else if (line[i] == 'P')
			print_player(game, i, index);
		else if (line[i] == 'B')
			print_bug(game, i, index);
		i++;
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
		game->textures.moves, 32, (game->rows - 1) * 32);
	mlx_string_put(game->mlx, game->win, 32 * 2, (game->rows * 32) - 10, \
		0x00000000, moves);
	// mlx_put_image_to_window(game->mlx, game->win, \
	// 	game->textures.coin, 32 * 3, (game->rows - 1) * 32);
	mlx_string_put(game->mlx, game->win, 32 * 3, (game->rows * 32) - 10, \
		0x00000000, "PROJECTS: ");
	mlx_string_put(game->mlx, game->win, (32 * 4) + 10, (game->rows * 32) - 10, \
		0x00000000, score);
	free(moves);
	free(score);
}

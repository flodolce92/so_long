/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:46:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/08 01:53:05 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_coin(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.coin, i * 32, (index * 32));
}

void	print_player(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.player, i * 32, (index * 32));
}

void	print_exit(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.door, i * 32, (index * 32));
}

void	print_wall(t_data *game, int i, int index)
{
	if (game->frames % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.wall, i * 32, (index * 32));
	else
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.wall2, i * 32, (index * 32));
}

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
		i++;
	}
}

void	fill_window(t_data *game)
{
	int		i;

	i = 0;
	while (game->map[i] != NULL)
	{
		print_map(game->map[i], game, i);
		i++;
	}
}

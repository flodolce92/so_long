/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:46:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/07 18:39:15 by flo-dolc         ###   ########.fr       */
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
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.wall, i * 32, (index * 32));
		else if (line[i] == '0')
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
		else if (line[i] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.coin, i * 32, (index * 32));
		}
		else if (line[i] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.door, i * 32, (index * 32));
		}
		else if (line[i] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 32, (index * 32));
			mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.player, i * 32, (index * 32));
		}
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

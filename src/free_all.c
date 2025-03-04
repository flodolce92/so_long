/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:45:30 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/05 21:38:18 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (i < game->rows)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		if (game->map_dup)
		{
			free(game->map_dup[i]);
			game->map_dup[i] = NULL;
		}
		i++;
	}
	free(game->map);
	if (game->map_dup)
		free(game->map_dup);
	game->map = NULL;
	game->map_dup = NULL;
}

void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_image(game->mlx, game->textures.wall2);
	mlx_destroy_image(game->mlx, game->textures.player);
	mlx_destroy_image(game->mlx, game->textures.player_left);
	mlx_destroy_image(game->mlx, game->textures.player_right);
	mlx_destroy_image(game->mlx, game->textures.player_back);
	mlx_destroy_image(game->mlx, game->textures.moves);
	mlx_destroy_image(game->mlx, game->textures.bug);
}

int	on_destroy(t_data *game)
{
	free_maps(game);
	if (game->mlx)
	{
		free_textures(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

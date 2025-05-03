/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:21:36 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/03 05:19:07 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_coin(t_data *game, int column, int row)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.coin, column * TILE_SIZE, (row * TILE_SIZE));
}

void	print_player(t_data *game, int column, int row)
{
	if (game->p_pos.direction == FRONT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player, column * TILE_SIZE, (row * TILE_SIZE));
	else if (game->p_pos.direction == BACK)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_back, column * TILE_SIZE, (row * TILE_SIZE));
	else if (game->p_pos.direction == LEFT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_left, column * TILE_SIZE, (row * TILE_SIZE));
	else if (game->p_pos.direction == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_right, column * TILE_SIZE, (row * TILE_SIZE));
}

void	print_exit(t_data *game, int column, int row)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.door, column * TILE_SIZE, (row * TILE_SIZE));
}

void	print_wall(t_data *game, int column, int row)
{
	if (game->frames % 10 == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.wall, column * TILE_SIZE, (row * TILE_SIZE));
	else if (game->frames % 10 == 5)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.wall2, column * TILE_SIZE, (row * TILE_SIZE));
}

void	print_bug(t_data *game, int column, int row)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.bug, column * TILE_SIZE, (row * TILE_SIZE));
}

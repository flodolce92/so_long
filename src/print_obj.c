/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:21:36 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/11 16:42:41 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_coin(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * TILE_SIZE, (index * TILE_SIZE));
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.coin, i * TILE_SIZE, (index * TILE_SIZE));
}

void	print_player(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * TILE_SIZE, (index * TILE_SIZE));
	if (game->p_pos.direction == FRONT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player, i * TILE_SIZE, (index * TILE_SIZE));
	else if (game->p_pos.direction == BACK)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_back, i * TILE_SIZE, (index * TILE_SIZE));
	else if (game->p_pos.direction == LEFT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_left, i * TILE_SIZE, (index * TILE_SIZE));
	else if (game->p_pos.direction == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_right, i * TILE_SIZE, (index * TILE_SIZE));
}

void	print_exit(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * TILE_SIZE, (index * TILE_SIZE));
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.door, i * TILE_SIZE, (index * TILE_SIZE));
}

void	print_wall(t_data *game, int i, int index)
{
	if (game->frames % 8 == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.wall, i * TILE_SIZE, (index * TILE_SIZE));
	else if (game->frames % 8 == 4)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.wall2, i * TILE_SIZE, (index * TILE_SIZE));
}

void	print_bug(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * TILE_SIZE, (index * TILE_SIZE));
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.bug, i * TILE_SIZE, (index * TILE_SIZE));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:06:32 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/08 22:03:32 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(t_data *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
		"assets/ground.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, \
		"assets/computer.xpm", &game->width, &game->height);
	game->textures.door = mlx_xpm_file_to_image(game->mlx, \
		"assets/hole.xpm", &game->width, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
		"assets/water1.xpm", &game->width, &game->height);
	game->textures.wall2 = mlx_xpm_file_to_image(game->mlx, \
		"assets/water2.xpm", &game->width, &game->height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
		"assets/player.xpm", &game->width, &game->height);
	game->textures.player_left = mlx_xpm_file_to_image(game->mlx, \
		"assets/player_left.xpm", &game->width, &game->height);
	game->textures.player_right = mlx_xpm_file_to_image(game->mlx, \
		"assets/player_right.xpm", &game->width, &game->height);
	game->textures.player_back = mlx_xpm_file_to_image(game->mlx, \
		"assets/player_back.xpm", &game->width, &game->height);
	game->textures.bug = mlx_xpm_file_to_image(game->mlx, \
		"assets/bug.xpm", &game->width, &game->height);
	game->textures.moves = mlx_xpm_file_to_image(game->mlx, \
		"assets/moves.xpm", &game->width, &game->height);
}

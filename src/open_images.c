/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:06:32 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/07 05:45:17 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_images(t_data *game)
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

void	open_images(t_data *game)
{
	if (open("assets/computer.xpm", O_RDONLY) == -1)
		error_message("assets/computer.xpm not found.", game);
	if (open("assets/hole.xpm", O_RDONLY) == -1)
		error_message("assets/hole.xpm not found.", game);
	if (open("assets/water1.xpm", O_RDONLY) == -1)
		error_message("assets/water1.xpm not found.", game);
	if (open("assets/water2.xpm", O_RDONLY) == -1)
		error_message("assets/water2.xpm not found.", game);
	if (open("assets/player.xpm", O_RDONLY) == -1)
		error_message("assets/player.xpm not found.", game);
	if (open("assets/player_left.xpm", O_RDONLY) == -1)
		error_message("assets/player_left.xpm not found.", game);
	if (open("assets/player_right.xpm", O_RDONLY) == -1)
		error_message("assets/player_right.xpm not found.", game);
	if (open("assets/player_back.xpm", O_RDONLY) == -1)
		error_message("assets/player_back.xpm not found.", game);
	if (open("assets/bug.xpm", O_RDONLY) == -1)
		error_message("assets/bug.xpm not found.", game);
	if (open("assets/moves.xpm", O_RDONLY) == -1)
		error_message("assets/moves.xpm not found.", game);
	load_images(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:06:32 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/07 02:12:27 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_ground_coins_door(t_data *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
		"assets/ground.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, \
		"assets/coin.xpm", &game->width, &game->height);
	game->textures.door = mlx_xpm_file_to_image(game->mlx, \
		"assets/hole.xpm", &game->width, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
		"assets/wall.xpm", &game->width, &game->height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
		"assets/player.xpm", &game->width, &game->height);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:45:30 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/24 10:45:53 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
}

int	on_destroy(t_data *game)
{
	free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}
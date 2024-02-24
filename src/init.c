/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:12:39 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/24 10:25:37 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_data *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->x = 0;
	game->y = 0;
	game->map = NULL;
	game->rows = 0;
	game->cols = 0;
	game->player = 0;
	game->coins = 0;
	game->exit = 0;
	game->moves = 0;
	game->score = 0;
	game->textures.ground = NULL;
	game->textures.coin = NULL;
	game->textures.door = NULL;
	game->textures.wall = NULL;
}
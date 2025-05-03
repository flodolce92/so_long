/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:04:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/03 05:22:47 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_press(int keycode, t_data *game)
{
	if (keycode == W)
	{
		game->p_pos.direction = BACK;
		game->keys.w = true;
	}
	else if (keycode == A)
	{
		game->p_pos.direction = LEFT;
		game->keys.a = true;
	}
	else if (keycode == S)
	{
		game->p_pos.direction = FRONT;
		game->keys.s = true;
	}
	else if (keycode == D)
	{
		game->p_pos.direction = RIGHT;
		game->keys.d = true;
	}
	else if (keycode == ESC)
		on_destroy(game);
	return (0);
}

int	handle_key_released(int keycode, t_data *game)
{
	if (keycode == W)
		game->keys.w = false;
	else if (keycode == A)
		game->keys.a = false;
	else if (keycode == S)
		game->keys.s = false;
	else if (keycode == D)
		game->keys.d = false;
	return (0);
}

int	loop_hook(t_data *game)
{
	game->frames++;
	update_player_position(game);
	fill_window(game);
	usleep(60000);
	return (0);
}

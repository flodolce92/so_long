/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:04:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/08 18:06:31 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		update_player_position(game, keycode);
	else if (keycode == ESC)
		on_destroy(game);
	return (0);
}

int	loop_hook(t_data *game)
{
	game->frames++;
	fill_window(game);
	usleep(4000);
	return (0);
}

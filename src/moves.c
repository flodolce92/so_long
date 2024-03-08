/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:37:42 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/08 03:28:04 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_data *game, int row, int col)
{
	if (game->map[row][col] == 'E' && game->coins != 0)
	{
		ft_putstr_fd("You need to collect all the coins first!\n", 1);
		return ;
	}
	game->map[game->p_pos.row][game->p_pos.col] = '0';
	game->p_pos.row = row;
	game->p_pos.col = col;
	if (game->map[game->p_pos.row][game->p_pos.col] == 'C')
	{
		game->coins--;
		game->score++;
		printf("Score: %d\n", game->score);
	}
	if (game->map[game->p_pos.row][game->p_pos.col] == 'E' && game->coins == 0)
	{
		ft_putstr_fd("You fell into the BlackHole!\n", 1);
		ft_putstr_fd("Enjoy the rest of your life in the void!\n", 1);
		on_destroy(game);
	}
	game->map[game->p_pos.row][game->p_pos.col] = 'P';
	game->moves++;
	printf("Moves: %d\n", game->moves);
	fill_window(game);
}

void	update_player_position(t_data *game, int keycode)
{
	if (keycode == W)
	{
		game->p_pos.direction = BACK;
		if (game->map[game->p_pos.row - 1][game->p_pos.col] != '1')
			move_player(game, game->p_pos.row - 1, game->p_pos.col);
	}
	else if (keycode == A)
	{
		game->p_pos.direction = LEFT;
		if (game->map[game->p_pos.row][game->p_pos.col - 1] != '1')
			move_player(game, game->p_pos.row, game->p_pos.col - 1);
	}
	else if (keycode == S)
	{
		game->p_pos.direction = FRONT;
		if (game->map[game->p_pos.row + 1][game->p_pos.col] != '1')
			move_player(game, game->p_pos.row + 1, game->p_pos.col);
	}
	else if (keycode == D)
	{
		game->p_pos.direction = RIGHT;
		if (game->map[game->p_pos.row][game->p_pos.col + 1] != '1')
			move_player(game, game->p_pos.row, game->p_pos.col + 1);
	}
}

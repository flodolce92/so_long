/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:37:42 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/07 20:25:10 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_data *game, int row, int col)
{
	if (game->map[row][col] == 'E' && game->coins != 0)
	{
		printf("You need to collect all the coins!\n");
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
		printf("You win!\n");
		on_destroy(game);
	}
	game->map[game->p_pos.row][game->p_pos.col] = 'P';
	game->moves++;
	printf("Moves: %d\n", game->moves);
	fill_window(game);
}

void	update_player_position(t_data *game, int keycode)
{
	if (keycode == 13)
	{
		if (game->map[game->p_pos.row - 1][game->p_pos.col] != '1')
			move_player(game, game->p_pos.row - 1, game->p_pos.col);
	}
	else if (keycode == 0)
	{
		if (game->map[game->p_pos.row][game->p_pos.col - 1] != '1')
			move_player(game, game->p_pos.row, game->p_pos.col - 1);
	}
	else if (keycode == 1)
	{
		if (game->map[game->p_pos.row + 1][game->p_pos.col] != '1')
			move_player(game, game->p_pos.row + 1, game->p_pos.col);
	}
	else if (keycode == 2)
	{
		if (game->map[game->p_pos.row][game->p_pos.col + 1] != '1')
			move_player(game, game->p_pos.row, game->p_pos.col + 1);
	}
}

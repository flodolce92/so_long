/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:37:42 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/04 03:53:23 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_check(t_data *game)
{
	if (game->map[game->p_pos.row][game->p_pos.col] == 'C')
	{
		game->coins--;
		game->score++;
		ft_putstr_fd("Score: ", 1);
		ft_putnbr_fd(game->score, 1);
		ft_putstr_fd("\n", 1);
	}
	if (game->map[game->p_pos.row][game->p_pos.col] == 'E' && game->coins == 0)
	{
		ft_putstr_fd("\nYou fell into the BlackHole!\n", 1);
		ft_putstr_fd("Enjoy the rest of your life in the void!\n", 1);
		on_destroy(game);
	}
	if (game->map[game->p_pos.row][game->p_pos.col] == 'B')
	{
		ft_putendl_fd("\nWatch out! That\'s a bug!", 1);
		ft_putendl_fd("Uh oh, looks like your code is infected", 1);
		ft_putendl_fd("----------------------------------------", 1);
		ft_putendl_fd("You\'re a loser, baby", 1);
		ft_putendl_fd("A loser, goddamn, baby", 1);
		ft_putendl_fd("You\'re a f*cked up little whiny b*tch", 1);
		ft_putendl_fd("You\'re a loser, just like me", 1);
		on_destroy(game);
	}
}

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
	move_check(game);
	game->map[game->p_pos.row][game->p_pos.col] = 'P';
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
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

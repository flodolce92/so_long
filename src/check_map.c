/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:56:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/05 21:43:05 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_closed_map(t_data *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (i == 0 || i == game->rows - 1)
			{
				if (game->map[i][j] != '1')
					error_message("Invalid map.", game);
			}
			else if (j == 0 || j == game->cols - 1)
			{
				if (game->map[i][j] != '1')
					error_message("Invalid map.", game);
			}
			j++;
		}
		i++;
	}
}

void	check_last_row(t_data *game)
{
	int		i;

	i = 0;
	while (i < game->cols)
	{
		if (game->map[game->rows - 1][i] != '1')
			error_message("Invalid map.", game);
		i++;
	}
	if (game->map[game->rows - 1][i] != '\0'
		&& game->map[game->rows - 1][i] != '\n')
		error_message("Invalid map.", game);
}

void	check_rect(t_data *game)
{
	int		i;
	int		row_len;

	i = 0;
	while (i < game->rows - 1)
	{
		row_len = ft_strlen(game->map[i]) - 1;
		if (row_len != game->cols)
			error_message("Invalid map.", game);
		i++;
	}
	if (game->cols < 3 || game->rows < 3)
		error_message("Invalid map.", game);
	if (game->cols == game->rows)
		error_message("Invalid map.", game);
}

void	count_map(t_data *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_pos.row = i;
				game->p_pos.col = j;
				game->player++;
			}
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->coins++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'B')
				error_message("Invalid map.", game);
		}
		i++;
	}
}

void	check_map(t_data *game)
{
	check_closed_map(game);
	check_last_row(game);
	check_rect(game);
	count_map(game);
	if (game->exit != 1 || game->coins < 1 || game->player != 1)
		error_message("Invalid map.", game);
}

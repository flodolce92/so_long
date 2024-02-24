/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:20:14 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/24 01:02:38 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validmove(t_data *game, int row, int col)
{
	return (game->map[row][col] != '1');
}

void	floodfill(t_data *game, int row, int col)
{
	if (!validmove(game, row, col) || game->map_dup[row][col] == '-')
		return ;
	game->map_dup[row][col] = '-';
	floodfill(game, row - 1, col);
	floodfill(game, row + 1, col);
	floodfill(game, row, col - 1);
	floodfill(game, row, col + 1);
}

void	duplicate_map(t_data *game) {
	int i;

	game->map_dup = (char **) malloc(sizeof(char *) * (game->rows + 1));
	if (game->map_dup == NULL)
	{
		ft_putstr_fd("Memory allocation failed.\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game->rows) {
		game->map_dup[i] = ft_strdup(game->map[i]);
		if (game->map_dup[i] == NULL) {
			ft_putstr_fd("Memory allocation failed.\n", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	game->map_dup[i] = NULL;
}

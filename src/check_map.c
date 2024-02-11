/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:56:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/09 15:07:30 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rect(t_data *game)
{
	int		i;
	int		row_len;

	i = 0;
	while (i < (*game).rows)
	{
		row_len = ft_strlen((*game).map[i]) - 1;
		if (row_len != (*game).cols)
		{
			ft_putstr_fd("Invalid map.\n", STDOUT_FILENO);
			exit(1);
		}
		i++;
	}
}

void	check_map(t_data *game)
{
	int		i;
	int		j;
	int		collect;
	int		exits;

	i = 0;
	collect = 0;
	exits = 0;
	check_rect(game);
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols - 1)
		{
			if ((*game).map[i][j] == 'P')
			{
				printf("Player found at %d, %d\n", i, j);
			}
			else if ((*game).map[i][j] == 'E')
			{
				printf("Exit found at %d, %d\n", i, j);
				exits++;
			}
			else if ((*game).map[i][j] == 'C')
			{
				printf("Collectible found at %d, %d\n", i, j);
				collect++;
			}
			else if ((*game).map[i][j] != '1' && (*game).map[i][j] != '0')
			{
				ft_putstr_fd("Invalid map.\n", STDOUT_FILENO);
				exit(1);
			}
			j++;
		}
		i++;
	}
	if (exits != 1 || collect < 1)
	{
		ft_putstr_fd("Invalid map.\n", STDOUT_FILENO);
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:46:08 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/06 17:46:29 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_rows(t_data *game, char *path_map)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		error_message("No map found.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
	}
	close(fd);
	free(line);
	game->rows = rows;
}

void	fill_map(t_data *game, char *path_map)
{
	int		fd;
	int		i;

	i = 0;
	get_rows(game, path_map);
	if (game->rows == 0)
		error_message("Invalid map.");
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		error_message("No map found.");
	game->map = (char **) malloc(sizeof(char *) * (game->rows + 1));
	if (game->map == NULL)
		error_message("Memory allocation failed.");
	while (i < game->rows)
	{
		game->map[i] = get_next_line(fd);
		if (!(game->map[i]))
			break ;
		i++;
	}
	game->map[i] = NULL;
	game->cols = ft_strlen(game->map[0]) - 1;
	close(fd);
}

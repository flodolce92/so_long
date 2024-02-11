/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:46:08 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/09 15:06:14 by flo-dolc         ###   ########.fr       */
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
	{
		ft_putstr_fd("No map found.\n", STDOUT_FILENO);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
	}
	close(fd);
	(*game).rows = rows;
}

void	fill_map(t_data *game, char *path_map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("No map found.\n", STDOUT_FILENO);
		exit(1);
	}
	(*game).map = (char **) malloc(sizeof(char *) * ((*game).rows + 1));
	while (i < (*game).rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*game).map[i] = line;
		i++;
	}
	(*game).map[i] = NULL;
	(*game).cols = ft_strlen((*game).map[0]) - 1;
	close(fd);
}

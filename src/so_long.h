/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:46:28 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/09 15:08:09 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		pX;
	int		pY;
	char	**map;
	int		rows;
	int		cols;
	int		player;
	int		collect;
	int		exit;
}	t_data;

void	get_rows(t_data *game, char *path_map);
void	fill_map(t_data *game, char *path_map);
void	check_map(t_data *game);

#endif

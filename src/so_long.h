/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:46:28 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/23 23:29:00 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_textures
{
	void	*ground;
	void	*coin;
	void	*door;
	void	*wall;
}	t_textures;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			x;
	int			y;
	char		**map;
	int			rows;
	int			cols;
	int			player;
	int			collect;
	int			exit;
	t_textures	textures;
}	t_data;

void	get_rows(t_data *game, char *path_map);
void	fill_map(t_data *game, char *path_map);
void	check_map(t_data *game);

#endif

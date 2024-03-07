/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:46:28 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/07 22:35:40 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
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
	void	*player;
}	t_textures;

typedef struct s_player
{
	int	row;
	int	col;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			x;
	int			y;
	char		**map;
	char		**map_dup;
	int			rows;
	int			cols;
	int			player;
	t_player	p_pos;
	int			coins;
	int			exit;
	int			moves;
	int			score;
	t_textures	textures;
}	t_data;

void	init_struct(t_data *game);
void	error_message(char *message);

void	get_rows(t_data *game, char *path_map);
void	check_map(t_data *game);
void	fill_map(t_data *game, char *path_map);
void	print_map(char *line, t_data *game, int index);
void	duplicate_map(t_data *game);
int		validmove(t_data *game, int row, int col);

void	open_images(t_data *game);
void	fill_window(t_data *game);

int		key_hook(int keycode, t_data *game);
void	update_player_position(t_data *game, int keycode);

void	free_map(t_data *game);
void	free_textures(t_data *game);
int		on_destroy(t_data *game);

#endif

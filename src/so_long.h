/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:46:28 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/05 21:40:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE_SIZE 64

enum e_keys
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307
};

enum e_directions
{
	FRONT,
	BACK,
	LEFT,
	RIGHT
};

typedef struct s_textures
{
	void	*ground;
	void	*coin;
	void	*door;
	void	*wall;
	void	*wall2;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_back;
	void	*bug;
	void	*moves;
}	t_textures;

typedef struct s_player
{
	int					row;
	int					col;
	enum e_directions	direction;
}	t_player;

typedef struct s_key_press
{
	bool	a;
	bool	d;
	bool	s;
	bool	w;
}	t_key_press;

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
	int			frames;
	t_key_press	keys;
}	t_data;

void	init_struct(t_data *game);
void	error_message(char *message, t_data *game);

void	get_rows(t_data *game, char *path_map);
void	check_map(t_data *game);
int		validmove(t_data *game, int row, int col);
void	fill_map(t_data *game, char *path_map);
void	duplicate_map(t_data *game);

void	print_map(char *line, t_data *game, int row);
void	print_player(t_data *game, int column, int row);
void	print_coin(t_data *game, int column, int row);
void	print_exit(t_data *game, int column, int row);
void	print_wall(t_data *game, int column, int row);
void	print_bug(t_data *game, int column, int row);

void	open_images(t_data *game);
void	fill_window(t_data *game);

int		loop_hook(t_data *game);
int		handle_key_press(int keycode, t_data *game);
int		handle_key_released(int keycode, t_data *game);
void	update_player_position(t_data *game);

void	free_maps(t_data *game);
void	free_textures(t_data *game);
int		on_destroy(t_data *game);

#endif

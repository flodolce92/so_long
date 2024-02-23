/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 07:58:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/23 23:18:36 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
}

int	on_destroy(t_data *game)
{
	free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 65307)
		on_destroy(game);
	return (0);
}

void  open_ground_coins_door(t_data *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
	"assets/ground.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, \
	"assets/coin.xpm", &game->width, &game->height);
	game->textures.door = mlx_xpm_file_to_image(game->mlx, \
	"assets/door.xpm", &game->width, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"assets/wall.xpm", &game->width, &game->height);
}

void	fill_window(t_data *game)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (i < (*game).rows)
	{
		j = 0;
		x = 0;
		while (j < (*game).cols)
		{
			if ((*game).map[i][j] == '1')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0x000000, "1");
			else if ((*game).map[i][j] == '0')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0xFFFFFF, "0");
			else if ((*game).map[i][j] == 'P')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0x00FF00, "P");
			else if ((*game).map[i][j] == 'E')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0xFF0000, "E");
			else if ((*game).map[i][j] == 'C')
				mlx_string_put((*game).mlx, (*game).win, x, y, 0x0000FF, "C");
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}

void	create_window(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed.\n", STDOUT_FILENO);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx,
				game->cols * 32,
				game->rows * 32,
				"so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: mlx_new_window failed.\n", STDOUT_FILENO);
		exit(1);
	}
	open_ground_coins_door(game);
	fill_window(game);
}

int	main(int ac, char **av)
{
	t_data	game;
	int		i;
	i = 0;
	if (ac < 2)
	{
		ft_putstr_fd("Too few parameters.\n", STDOUT_FILENO);
		return (1);
	}
	fill_map(&game, av[1]);
	// printf("Map rows: %d\n", game.rows);
	// printf("Map cols: %d\n", game.cols);
	// while (game.map[i] != NULL)
	// {
	// 	printf("Map line %d:\t%s", i, game.map[i]);
	// 	i++;
	// }
	check_map(&game);
	create_window(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, on_destroy, &game);
	mlx_loop(game.mlx);
	exit(0);
	return (0);
}

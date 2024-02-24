/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 07:58:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/24 10:46:51 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 13 || keycode == 0 \
	|| keycode == 1 || keycode == 2)
		printf("keycode: %d\n", keycode);
		// update_player_position(game, keycode);
	else if (keycode == 53)
		on_destroy(game);
	return (0);
}

void	open_ground_coins_door(t_data *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
		"assets/ground.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, \
		"assets/coin.xpm", &game->width, &game->height);
	game->textures.door = mlx_xpm_file_to_image(game->mlx, \
		"assets/door.xpm", &game->width, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
		"assets/wall.xpm", &game->width, &game->height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
		"assets/player.xpm", &game->width, &game->height);
}

void	create_window(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed.\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx,
			game->cols * 32,
			game->rows * 32,
			"so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: mlx_new_window failed.\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
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
	init_struct(&game);
	fill_map(&game, av[1]);
	check_map(&game);
	create_window(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, on_destroy, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

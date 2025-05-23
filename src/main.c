/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 07:58:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/07 05:50:04 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message, t_data *game)
{
	ft_putstr_fd("Error: ", STDOUT_FILENO);
	ft_putendl_fd(message, STDOUT_FILENO);
	if (game)
		on_destroy(game);
	exit(EXIT_FAILURE);
}

void	create_window(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_message("mlx_init failed.", game);
	game->win = mlx_new_window(game->mlx,
			game->cols * TILE_SIZE,
			game->rows * TILE_SIZE,
			"so_long");
	if (!game->win)
		error_message("mlx_new_window failed.", game);
	open_images(game);
	fill_window(game);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		error_message("Wrong number of arguments. \
			\nUsage: ./so_long <map.ber>", NULL);
	if (!ft_strnstr((av[1] + ft_strlen(av[1]) - 4), ".ber", 4))
		error_message("Invalid file type. Must be: \"<name>.ber\"", NULL);
	init_struct(&game);
	fill_map(&game, av[1]);
	check_map(&game);
	duplicate_map(&game);
	create_window(&game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, handle_key_released, &game);
	mlx_hook(game.win, 17, 1L << 17, on_destroy, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

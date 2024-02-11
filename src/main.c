/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:36:52 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/02/09 08:06:21 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	t_data	img;

// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
// 	win_ptr = mlx_new_window(mlx_ptr, 1280, 720, "ADDIOS");
// 	if (!win_ptr)
// 		return (free(mlx_ptr), 1);
// 	img.img = mlx_new_image(mlx_ptr, 1280, 720);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	mlx_loop(mlx_ptr);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	free(mlx_ptr);
// 	return (0);
// }

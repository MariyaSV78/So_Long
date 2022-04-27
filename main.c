/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:00:39 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 11:09:55 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	ft_error_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of argument", 2);
		return (0);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", ft_strlen(argv[1])) != 0)
	{
		ft_putstr_fd("Error\nInvalid of the file extention", 2);
		return (0);
	}
	if (ft_strlen(argv[1]) < 4)
	{
		ft_putstr_fd("Error\nInvalid of argument", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!ft_error_arg(argc, argv))
		exit(0);
	ft_init_data(&game);
	if (!ft_parsing_data(&game, argv[1]))
		ft_free(&game);
	game.mlx.mlx = mlx_init();
	if (!game.mlx.mlx)
		ft_error("Error\nmlx not found", &game);
	ft_img_load(&game);
	game.mlx.win = mlx_new_window(game.mlx.mlx, game.l_map * game.size_block,
			game.h_map * game.size_block, "SoLong");
	if (!game.mlx.win)
		ft_error("Error\nmlx win connot initialize", &game);
	mlx_loop_hook(game.mlx.mlx, ft_map_drawing, &game);
	mlx_key_hook(game.mlx.win, ft_key_hook, &game);
	mlx_hook(game.mlx.win, 33, 1L << 5, ft_exit_hook, &game);
	mlx_hook(game.mlx.win, 15, 1L << 16, ft_reduce_window, &game);
	mlx_loop(game.mlx.mlx);
	ft_free(&game);
}

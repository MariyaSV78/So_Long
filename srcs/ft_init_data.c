/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:58:34 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 11:40:21 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_error_size(t_game *game, int img_width, int img_height)
{
	if (img_width != game->size_block || img_height != game->size_block)
		ft_error ("Error\nImage(s) has a bad size", game);
}

void	ft_img_load(t_game *game)
{
	int		img_width;
	int		img_height;

	img_width = 32;
	img_height = 32;
	game->mlx.img_pers = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/pers.xpm", &img_width, &img_height);
	ft_img_error_size(game, img_width, img_height);
	game->mlx.img_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/wall.xpm", &img_width, &img_height);
	ft_img_error_size(game, img_width, img_height);
	game->mlx.img_colect = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/collect.xpm", &img_width, &img_height);
	ft_img_error_size(game, img_width, img_height);
	game->mlx.img_backgr = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/snow.xpm", &img_width, &img_height);
	ft_img_error_size(game, img_width, img_height);
	game->mlx.img_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/exit.xpm", &img_width, &img_height);
	ft_img_error_size(game, img_width, img_height);
	if (!game->mlx.img_pers || !game->mlx.img_wall || !game->mlx.img_colect
		|| !game->mlx.img_backgr || !game->mlx.img_exit)
		ft_error ("Error\nImage(s) not found", game);
}

void	ft_init_data(t_game *game)
{
	game->map = NULL;
	game->mlx.win = NULL;
	game->mlx.mlx = NULL;
	game->mlx.img_pers = NULL;
	game->mlx.img_wall = NULL;
	game->mlx.img_colect = NULL;
	game->mlx.img_backgr = NULL;
	game->mlx.img_exit = NULL;
	game->l_map = 0;
	game->h_map = 0;
	game->size_block = 32;
	game->nbr_move = 0;
	game->nbr_colect = 0;
	game->nbr_exit = 0;
	game->nbr_pers = 0;
}

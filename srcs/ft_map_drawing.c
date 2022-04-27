/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 06:43:12 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/18 19:45:59 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	x *= game->size_block;
	y *= game->size_block;
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, img, x, y);
}

int	ft_map_drawing(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->h_map)
	{
		x = 0;
		while (x < game->l_map)
		{
			if (game->map[y][x] == '1')
				put_image(game, game->mlx.img_wall, x, y);
			else if (game->map[y][x] == 'P')
				put_image(game, game->mlx.img_pers, x, y);
			else if (game->map[y][x] == 'C')
				put_image(game, game->mlx.img_colect, x, y);
			else if (game->map[y][x] == 'E')
				put_image(game, game->mlx.img_exit, x, y);
			else if (game->map[y][x] == '0')
				put_image(game, game->mlx.img_backgr, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

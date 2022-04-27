/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:02:52 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 11:16:47 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_game *game, int dy, int dx)
{
	int	x;
	int	y;

	x = game->x_pers;
	y = game->y_pers;
	if (game->map[y + dy][x + dx] == 'E' && game->nbr_colect == 0)
	{
		game->nbr_move++;
		ft_putnbr_fd(game->nbr_move, 1);
		ft_putchar_fd('\n', 1);
		ft_free(game);
	}
	if (game->map[y + dy][x + dx] == '0' || game->map[y + dy][x + dx] == 'C')
	{
		if (game->map[y + dy][x + dx] == 'C')
			game->nbr_colect--;
		game->map[y][x] = '0';
		game->map[y + dy][x + dx] = 'P';
		game->x_pers += dx;
		game->y_pers += dy;
		game->nbr_move++;
		ft_putnbr_fd(game->nbr_move, 1);
		ft_putchar_fd('\n', 1);
	}
}

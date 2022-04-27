/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:21:05 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 11:16:22 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	ft_exit_hook(t_game *game)
{
	ft_free(game);
	return (0);
}

int	ft_reduce_window(t_game *game)
{
	ft_map_drawing(game);
	return (1);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_exit_hook(game);
	if (keycode == 119)
		ft_move_player(game, -1, 0);
	if (keycode == 100)
		ft_move_player(game, 0, 1);
	if (keycode == 97)
		ft_move_player(game, 0, -1);
	if (keycode == 115)
		ft_move_player(game, 1, 0);
	return (1);
}

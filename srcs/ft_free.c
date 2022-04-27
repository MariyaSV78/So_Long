/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:52:01 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 11:18:07 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->h_map)
		{
			free(game->map[i]);
			i++;
		}
		free (game->map);
	}
	ft_mlx_destroy(&game->mlx);
	free(game->mlx.mlx);
	exit(0);
}

void	ft_mlx_destroy(t_mlx *mlx)
{
	if (mlx->img_pers)
		mlx_destroy_image(mlx->mlx, mlx->img_pers);
	if (mlx->img_wall)
		mlx_destroy_image(mlx->mlx, mlx->img_wall);
	if (mlx->img_colect)
		mlx_destroy_image(mlx->mlx, mlx->img_colect);
	if (mlx->img_backgr)
		mlx_destroy_image(mlx->mlx, mlx->img_backgr);
	if (mlx->img_exit)
		mlx_destroy_image(mlx->mlx, mlx->img_exit);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
}

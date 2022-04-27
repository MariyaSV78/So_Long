/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:07:44 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/22 18:19:37 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	ft_check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->h_map)
	{
		x = 0;
		while (x < game->l_map)
		{
			if ((game->map[0][x] != '1') || (game->map[y][0] != '1')
				|| (game->map[y][game->l_map - 1] != '1')
				|| (game->map[game->h_map - 1][x] != '1'))
				ft_error("Error\n The map must be surrounded by walls", game);
			x++;
		}
		y++;
	}
}

void	ft_check_personage(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'P')
	{
		game->nbr_pers++;
		game->x_pers = x;
		game->y_pers = y;
	}
}

void	ft_check_elems(t_game *game, int y, int x)
{
	if (game->map[y][x] != 'P' && game->map[y][x] != 'C'
		&& game->map[y][x] != 'E' && game->map[y][x] != '1'
		&& game->map[y][x] != '0')
		ft_error("Error\nMap contains forbidden element(s)", game);
	if (game->map[y][x] == 'C')
		game->nbr_colect++;
	if (game->map[y][x] == 'E')
		game->nbr_exit++;
}

void	ft_check_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	ft_check_walls(game);
	while (y < game->h_map)
	{
		x = 0;
		while (x < game->l_map)
		{
			ft_check_personage(game, y, x);
			ft_check_elems(game, y, x);
			x++;
		}
		y++;
	}
	if (game->nbr_pers != 1)
		ft_error("Error\nOnly one player should be on the map", game);
	if (game->nbr_colect == 0)
		ft_error("Error\nMap must have at least one collectible", game);
	if (game->nbr_exit == 0)
		ft_error("Error\nMap must have at least one exit", game);
}

int	ft_init_map(t_game *game, char *file_name)
{
	int	i;
	int	fd;

	if (game->h_map == 0 || game->l_map == 0)
		ft_error("Error\nThe map has incorrect size", game);
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap cannot be read", game);
	game->map = (char **)malloc(sizeof(char *) * game->h_map);
	if (!game->map)
		ft_error("Cannot allocated memory", game);
	while (i < game->h_map)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	ft_check_map(game);
	return (1);
}

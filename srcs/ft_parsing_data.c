/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:42:32 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/22 20:25:10 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	ft_nbr_lines(t_game *game, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) - 1 == 0)
		{
			free(line);
			break ;
		}
		if (game->h_map == 0)
			game->l_map = ft_strlen(line) - 1;
		else if (game->l_map != (int)ft_strlen(line) - 1)
		{
			free(line);
			ft_error("Error\nThe map is not rectangular", game);
		}
		game->h_map++;
		free(line);
	}
}

int	ft_parsing_data(t_game *game, char *map_ber)
{
	int		fd;

	fd = open(map_ber, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap cannot be read", game);
	ft_nbr_lines(game, fd);
	close(fd);
	ft_init_map(game, map_ber);
	return (1);
}

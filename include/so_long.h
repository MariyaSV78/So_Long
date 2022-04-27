/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:41:19 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/18 19:02:06 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_pers;
	void	*img_wall;
	void	*img_colect;
	void	*img_backgr;
	void	*img_exit;
}		t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	int		l_map;
	int		h_map;
	char	**map;
	int		size_block;
	int		nbr_move;
	int		nbr_colect;
	int		nbr_exit;
	int		nbr_pers;
	int		x_pers;
	int		y_pers;
}		t_game;

int		ft_parsing_data(t_game *game, char *map_ber);
void	ft_init_data(t_game *game);
int		ft_init_map(t_game *game, char *file_name);
int		ft_error_arg(int argc, char *argv[]);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str_1, const char *str_2, size_t n);
char	*ft_strrchr(const char *str, int ch);
size_t	ft_strlcpy(char *dest, const char *str, size_t n);
char	*ft_strchr(const char *str, int ch);
void	ft_free(t_game *game);
void	ft_mlx_destroy(t_mlx *mlx);
void	ft_error(const char *error_message, t_game *game);
int		ft_key_hook(int keycode, t_game *game);
int		ft_exit_hook(t_game *game);
int		ft_map_drawing(t_game *game);
void	ft_img_load(t_game *game);
int		ft_reduce_window(t_game *game);
void	ft_move_player(t_game *game, int dx, int dy);
#endif

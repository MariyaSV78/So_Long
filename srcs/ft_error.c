/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:35:37 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 11:11:16 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(const char *error_message, t_game *game)
{
	ft_putstr_fd(error_message, 2);
	ft_free(game);
	exit(0);
}

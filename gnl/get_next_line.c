/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:08:04 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/10 11:30:04 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_readbuffer	r_buff = {.start = 0};
	int					end;
	char				*line;

	if (BUFFER_SIZE < 0 || fd < 0 || fd == 1 || fd == 2 || fd >= FD_MAX)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (r_buff.start == 0)
			r_buff.n = read(fd, r_buff.buf, BUFFER_SIZE);
		if (r_buff.n < 0)
			return (NULL);
		if (r_buff.n == 0)
			return (line);
		end = ft_findend(r_buff.buf, r_buff.start, r_buff.n);
		if (end < r_buff.n)
		{
			line = ft_newline(line, r_buff.buf, r_buff.start, end + 1);
			r_buff.start = end + 1;
			return (line);
		}
		line = ft_newline(line, r_buff.buf, r_buff.start, end);
		r_buff.start = 0;
	}
}

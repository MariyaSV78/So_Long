/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:08:47 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/10 10:55:05 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# define FD_MAX 1000
# define BUFFER_SIZE 1024

typedef struct s_readbuffer
{
	int		start;
	ssize_t	n;
	char	buf[BUFFER_SIZE];
}			t_readbuffer;

char	*get_next_line(int fd);
int		ft_len_line(char *line);
int		ft_findend(char *buf, int i, int n);
char	*ft_newline(char *temp_line, char *buf, int start, int end);

#endif

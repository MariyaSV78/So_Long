/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:09:02 by msosnova          #+#    #+#             */
/*   Updated: 2021/07/08 11:50:04 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_findend(char *buf, int end, int n)
{
	while (end < n)
	{
		if (buf[end] == '\n')
			return (end);
		end++;
	}
	return (end);
}

int	ft_len_line(char *line)
{
	unsigned int	i;

	i = 0;
	if (line == 0)
		return (i);
	while (line[i])
		i++;
	return (i);
}

char	*ft_newline(char *temp_line, char *buf, int start, int end)
{
	int		j;
	char	*line;
	int		len_temp_line;

	if (end == start)
		return (temp_line);
	len_temp_line = ft_len_line(temp_line);
	line = (char *)malloc(sizeof(char) * (end - start + len_temp_line + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < len_temp_line)
	{
		line[j] = temp_line[j];
		j++;
	}
	while (start < end)
		line[j++] = buf[start++];
	line[j] = '\0';
	free(temp_line);
	return (line);
}

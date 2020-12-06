/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:53:13 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/06 18:27:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static int	s;
	char		*str_buff;
	ssize_t		read_returned;
	int			i;

	if (fd <= -1 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE < 0)
		return (-1);
	if (!(str_buff = malloc(sizeof(*str_buff) * (BUFFER_SIZE + 1))))
		return (-1);
	read_returned = read(fd, str_buff, BUFFER_SIZE);
	str_buff[read_returned] = 0;
	if (read_returned == -1)
	{
		free(str_buff);
		return (-1);
	}
	i = s;
	while (str_buff[s] != 0 && s < BUFFER_SIZE)
	{
		if (str_buff[s] == '\n')
		{
			str_buff[s] = 0;
			*line = ft_strjoin(*line, str_buff, i);
			s++;		
			//libere tout ce qu'on a malloc
			free(str_buff);
			return (1);
		}
		s++;
	}
	if (str_buff[s] == 0 || s == BUFFER_SIZE)
	{
		str_buff[s] = 0;
		*line = ft_strjoin(*line, str_buff, i);
		free(str_buff);
		return (0);
	}
	return (-1);
}

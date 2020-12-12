/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:53:13 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/11 16:43:15 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
** Takes a string, and returns the position of '\n' inside or -1 if no new line
*/
static int	ret_in_str(char *str)
{
	int i;

	if (str == 0)
		return (-1);
	i = 0;
	while(str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*
** All the possible cases of errors in arguments of get_next_line
*/
static int	error_cases(int fd, char **line)
{
	if (fd <= -1 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
		return (1);
	return (0);
}

/*
** When there is a '\n' in the middle of the saved line, it saves all after
** the first '\n' encountered in the static remainer and returns its address 
*/
static char	*save_remainer(char **line, int i)
{
	char	*remainer;
	int		remainer_size;
	int		j;

	j = 0;
	remainer_size = ft_strlen(&(*line)[i + 1]);
	if (!(remainer = malloc(sizeof(*remainer) * (remainer_size + 1))))
		return (0);
	while ((*line)[i + 1] != 0)
	{
		remainer[j] = (*line)[i + 1];
		i++;
		j++; 
	}
	remainer[j] = 0;
	return (remainer);
}

/*
** 2 possible cases: 
** 1) Remainer has no '\n' inside, then we just copy it to *line. Returns 1.
** 2) remainer has a '\n' inside, then we copy all until it and stop gnl. 
** Returns 0 if an error was encountered
*/
static int	ft_copy_from_remainer(char **remainer, char **line, size_t *line_size)
{
	char *temp_remainer;
	int n;

	temp_remainer = 0;
	if (ret_in_str(*remainer) < 0)
	{
		*line_size = ft_strlen(*remainer);
		if (!ft_save_to_line(line, *remainer, *line_size))
			return (0);
		free(*remainer);
		return (1);
	}
	else
	{
		n = ret_in_str(*remainer);
		temp_remainer = ft_strcpy(&(*remainer)[n + 1]);
		(*remainer)[n] = 0;
		*line_size = ft_strlen(*remainer);
		if (!ft_save_to_line(line, *remainer, *line_size))
			return (0);
		free(*remainer);
		if(!(*remainer = malloc(sizeof(*remainer) * ft_strlen(temp_remainer))))
			return (0);
		*remainer = ft_strcpy(temp_remainer);
		return (2);
	}
}

int				get_next_line(int fd, char **line)
{
	static char	*remainer = 0;
	char		*str_buff;
	ssize_t		read_ret;
	size_t		line_size;
	int rem;

	if (line != 0 && *line != 0)
		(*line)[0] = 0;
	line_size = 0;
	if (error_cases(fd, line) == 1)
		return (ft_free(0, remainer, 0, 1));
	if (!(str_buff = malloc(sizeof(*str_buff) * (BUFFER_SIZE + 1))))
		return (ft_free(str_buff, remainer, 0, 1));
	if (remainer != 0)
	{
		rem = ft_copy_from_remainer(&remainer, line, &line_size);
		if (rem == 2)
			return (1);
		else if (rem == 0)
		{
			return (ft_free(str_buff, remainer, 1, 1));
		}
		remainer = 0;
	}
	while ((read_ret = read(fd, str_buff, BUFFER_SIZE)) > 0)
	{
		str_buff[read_ret] = 0;
		line_size += BUFFER_SIZE;
		if (!ft_save_to_line(line, str_buff, line_size))
		{
			return (ft_free(str_buff, remainer, 1, 0));
		}
		if (ret_in_str(*line) >= 0)
			break ;
	}
	if (read_ret == -1)
	{
		return (ft_free(str_buff, remainer, 1, 0));
	}
	if (read_ret == 0)
	{
		return (ft_free(str_buff, remainer, 1, 0) + 1);
	}
	if (ret_in_str(*line) >= 0)
	{
		if (!(remainer = save_remainer(line, ret_in_str(*line))))
		{
			return (ft_free(str_buff, remainer, 1, 1));
		}
		(*line)[ret_in_str(*line)] = 0;
		return (ft_free(str_buff, remainer, 1, 0) + 2);
	}
	return (-1);
}
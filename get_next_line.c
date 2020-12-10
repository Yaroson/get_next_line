/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:53:13 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/10 14:15:11 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
** Takes a string, and returns the position of '\n' inside or -1 if no new line
*/
static int	ret_in_str(char *str)
{
	int i;

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

	//printf("Saving the remainer\n");
	j = 0;
	//printf("line before used in save remainer: %s\n", *line);
	remainer_size = ft_strlen(&(*line)[i + 1]);
	//printf("&line[i+1]: %s\n", ft_strcpy(&(*line)[i + 1]));
	//printf("remainer_size: %d\n",remainer_size);
	if (!(remainer = malloc(sizeof(*remainer) * (remainer_size + 1))))
		return (0);
	//printf("Malloc ok\n");
	while ((*line)[i + 1] != 0)
	{
		remainer[j] = (*line)[i + 1];
		i++;
		j++; 
	}
	remainer[j] = 0;
	//printf("Remainer: %s\n", remainer);
	return (remainer);
}

/*
** 2 possible cases: remainer has no '\n' inside, then we just copy it to *line
** and remainer has a '\n' inside, then we copy all until it and stop gnl
*/
static int	ft_copy_from_remainer(char **remainer, char **line, size_t *line_size)
{
	char *temp_remainer;
	int n;

	//printf("here I am, copying from the remainer\n");
	temp_remainer = 0;
	if (ret_in_str(*remainer) < 0)
	{
		//printf("no new line in the remainer\n");
		*line_size = ft_strlen(*remainer);
		//proteger?
		ft_save_to_line(line, *remainer, *line_size);
		//printf("Line after copying from the remainer: %s\n", *line);
		free(*remainer);
		return (1);
	}
	else
	{
		//printf("new line in the remainer\n");
		n = ret_in_str(*remainer);
		temp_remainer = ft_strcpy(&(*remainer)[n + 1]);
		(*remainer)[n] = 0;
		*line_size = ft_strlen(*remainer);
		ft_save_to_line(line, *remainer, *line_size);
		free(*remainer);
		if(!(*remainer = malloc(sizeof(*remainer) * ft_strlen(temp_remainer))))
			return (0);
		*remainer = ft_strcpy(temp_remainer);
		//printf("Remaining remainer: %s\n", *remainer);
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

	*line = 0;
	line_size = 0;
	if (error_cases(fd, line) == 1)
	{
		//printf("error case\n");
		return (-1);
	}
	if (!(str_buff = malloc(sizeof(*str_buff) * (BUFFER_SIZE + 1))))
	{
		//printf("Malloc str_buff error\n");
		return (-1);
	}
	//printf("Remainer at the start: %s\n", remainer);
	if (remainer != 0)
	{
		rem = ft_copy_from_remainer(&remainer, line, &line_size);
		if (rem == 2)
			return (1);
		else if (rem == 0)
		{
			//printf("Copy from remainer error\n");
			return (-1);
		}	
		remainer = 0;
	}
	//printf("Reading now \n");
	while ((read_ret = read(fd, str_buff, BUFFER_SIZE)) > 0)
	{
		//printf("str_buff after read done: %s\n", str_buff);
		//printf("read_ret: %zd\n", read_ret);
		str_buff[read_ret] = 0;
		line_size += BUFFER_SIZE;
		ft_save_to_line(line, str_buff, line_size);	
		//printf("line: %s\n", *line);
		if (ret_in_str(*line) >= 0)
		{
			//printf("ret in line: %d\n", ret_in_str(*line));
			break;
		}
	}
	if (read_ret == -1)
	{
		//printf("Read_ret error\n");
		//free stuff
		return (-1);
	}
	if (read_ret == 0)
	{
		//printf("Reading returned 0");
		return (0);
	}
	if (ret_in_str(*line) >= 0)
	{
		//printf("\\n in *line!\n");
		//printf("str_buff: %s\n", str_buff);
		//printf("read_ret: %zd\n", read_ret);
		remainer = save_remainer(line, ret_in_str(*line));
		(*line)[ret_in_str(*line)] = 0;
		return (1);
	}
	return (1);
}
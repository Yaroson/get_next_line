/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:55:38 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/10 12:01:26 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

//FOR MALLOC/FREE
# include <stdlib.h>
//FOR SSIZE_T && read
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
//FOR BUFF_MAX
# include <limits.h>
//FOR OPEN
# include <fcntl.h>
# include <stdio.h>

char		*ft_strcpy(char *line);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
int			ft_save_to_line(char **line, char *str_buff, size_t line_size);

#endif
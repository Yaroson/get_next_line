/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:55:38 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/22 09:16:42 by ysoroko          ###   ########.fr       */
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


#ifndef BUFFER_SIZE
#define BUFFER_SIZE  32
#endif

char		*ft_strcpy(char *line);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *str);
int			ft_save_to_line(char **line, char *str_buff, size_t line_size);
int			ft_free(char *s_buff, char *rem, int s_b_flag, int r_flag);

#endif
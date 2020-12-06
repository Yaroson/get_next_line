/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:55:38 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/06 16:39:25 by ysoroko          ###   ########.fr       */
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

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *pref, char const *suff, int s);

#endif
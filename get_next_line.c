/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:53:13 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/04 18:07:30 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char	*current_ptr;
	char		*str_buff;
	ssize_t		read_returned;
	ssize_t		i;

	if (fd <= -1 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE < 0)
		return (-1);
	if (!(str_buff = malloc(sizeof(*str_buff) * (BUFFER_SIZE + 1))))
		return (-1);
	read_returned = read(fd, str_buff, BUFFER_SIZE);
	if (read_returned == -1)
	{
		free(str_buff);
		return (-1);
	}
	current_ptr = str_buff;
	str_buff[read_returned] == '\0';
	i = 0;
	while (str_buff[i] != 0 && i < BUFFER_SIZE)
	{
		if (str_buff[i] == '\n')
		{
			//ecrire une fonction qui collerait la noubvelle ligne au *line
			ft_coller(*line, current_ptr, i);
			current_ptr = &str_buff[i];
			//libere tout ce qu'on a malloc
			ft_delete(str)
		}
	}
	


}



//1)read renvoit la longueur totale lue et stock tout ce qui a ete
//	lu dabs str_buff;

//2)on lit alors str_buff jusqu'à ce qu'on rencontre un \n

//3)lorsqu'on le rencontre, on ajoute tout ce qu'on a lu dans *line

//4)et on supprime la partie copiee de str_buff

//5)il faut tout free!
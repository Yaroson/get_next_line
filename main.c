/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:23:07 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/06 18:14:29 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;
	char *str;
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open Error\n");
		return (0);
	}
	while (get_next_line(fd, &str) > 0)
	{
		fd = open("test.txt", O_RDONLY);
	}
	printf("%s\n", str);
	return (0);
}
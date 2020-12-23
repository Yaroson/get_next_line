/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:23:07 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/23 11:29:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

// int main(void)
// {
//     int fd1 = open("test.txt", O_RDONLY);
//     int fd2 = open("test2.txt", O_RDONLY);
//     int fd3 = open("test3.txt", O_RDONLY);
//     int fd4 = open("test4.txt", O_RDONLY);
//     int     i;
//     char    *cou;
// //  cou = 0;
//     char    sc = 'l';
//     int a = 1;
//     int b = 1;
//     int c = 1;
//     int d = 1;
// /*   char    *zero;
//     zero = 0;
//     printf("%s\n", zero);
//     return (0);  */
//     while (sc != 'a')
//     {
//         if (sc == '1')
//         {
//             i = get_next_line(fd1, &cou);
//             printf("line of fd1 with return value : %d\n", i);
//             printf("%s\n\n", cou);
//             free(cou);
//             sc = 'l';
//             a = i;
//         }
//         if (sc == '2')
//         {
//             i = get_next_line(fd2, &cou);
//             printf("line of fd2 with return value : %d\n", i);
//             printf("%s\n\n", cou);
//             free(cou);
//             sc = 'l';
//             b = i;
//         }
//         if (sc == '3')
//         {
//             i = get_next_line(fd3, &cou);
//             printf("line of fd3 with return value : %d\n", i);
//             printf("%s\n\n", cou);
//             free(cou);
//             sc = 'l';
//             c = i;
//         }
//         if (sc == '4')
//         {
//             i = get_next_line(fd4, &cou);
//             printf("line of fd4 with return value : %d\n", i);
//             printf("%s\n\n", cou);
//             free(cou);
//             sc = 'l';
//             d = i;
//         }
// /*         if (!a && !b && !c && !d)
//         {
//             printf("COUCOU");
//             break ;
//         } */
//         sc = getchar();
//     }
//     return (0);
// }
 
int main()
{
	int fd;
	char *str = 0;
	int count = 1;
	int i = 0;
	char *str_tab[20];
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open Error\n");
		return (0);
	}


	//TO TEST ALL THE LINES AT THE SAME TIME
	while (printf("\n\nSTART %d\n\n", count), get_next_line(fd, &str) > 0)
	{
		strcpy(str_tab[i], str);
		i++;
		printf("%d: Line: %s\n", count, str);
		count++;
	}
	printf("%d: Line: %s\n\n\n\n\n", count, str);
	strcpy(str_tab[i], str);
	i++;
	str_tab[i] = 0;
	i = 0;
	
	while (str_tab[i] != 0)
	{
		printf("%d: Line: %s\n\n", i + 1, str_tab[i]);
		i++;
	}

	//TO TEST LINES ONE BY ONE
	// printf("GNL RETURNED: %d\n",get_next_line(fd, &str));
	// printf("Line 1: %s\n", str);
	// printf("GNL RETURNED: %d\n",get_next_line(fd, &str));
	// printf("Line 2: %s\n", str);
	// printf("%d\n",get_next_line(fd, &str));
	// printf("Last  Line: %s\n", str);
	free(str);
	return (0);
}


//TO TRY:	BUFF_SIZE = 0 / 1 / 4 / -1 / 800000 
//			fd = 0 / -1 / 68 / 99999999
//			file with: /Long lines / short lines (<4) / empty lines (single / multiple / only)
//			input (fd = 1) 



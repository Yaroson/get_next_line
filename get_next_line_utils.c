/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:58:51 by ysoroko           #+#    #+#             */
/*   Updated: 2020/12/06 18:24:20 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int		i;
	char	*my_src;

	my_src = (char *)(src);
	i = 0;
	while (my_src[i] != '\0')
	{
		dest[i] = my_src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*ft_strdup(const char *src)
{
	char *str;
	char *my_src;

	my_src = (char *)(src);
	if (!(str = malloc(sizeof(*str) * (ft_strlen(my_src) + 1))))
		return (0);
	return (ft_strcpy(str, my_src));
}

char	*ft_strjoin(char const *pref, char const *suff, int s)
{
	char	*ret;
	char	*my_pref;
	char	*my_suff;
	size_t	i;
	size_t	j;

	if (pref == 0 && suff != 0)
	{
		my_suff = ft_strdup(suff);
		return (my_suff);
	}
	if (suff == 0 && pref != 0)
	{
		my_pref = ft_strdup(pref);
		return (my_pref);
	}
	if (suff == 0 && pref == 0)
		return (0);
	i = -1;
	j = -1;
	my_pref = (char *)(pref);
	my_suff = (char *)(&suff[s]);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(my_pref) + ft_strlen(my_suff) + 2))))
		return (0);
	while (my_pref[++i] != '\0')
		ret[i] = pref[i];
	if (s != 0)
		ret[i++] = '\n';
	while (my_suff[++j] != '\0')
	{
		ret[i] = my_suff[j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
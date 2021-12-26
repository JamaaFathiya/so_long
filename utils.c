/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:49:06 by fathjami          #+#    #+#             */
/*   Updated: 2021/12/26 11:34:59 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == uc)
			return ((void *)tmp + i);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


int len(char *str)
{
	int i;

	i = 0;
	while(str[i++]);
	return i;
}

char *duup(char *str)
{
	int i;
	char *res;

	i = 0;
	res = (char *) malloc(len(str) * sizeof(char));
	if (!res)
		return(NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return res;
}

char *get_next_line(int fd)
{
	int i;
	char line[1000000];
	char buf;

	i = 0;
	if(fd < 0)
		return(NULL);
	while (read(fd, &buf, 1) > 0)
	{
		line[i++] = buf;
		if (buf == '\n')
		{
			line[i] = '\0';
			return(duup(line));
		}
	}
	line[i] = '\0';
	if(!line[0])
		return (NULL);
	return(duup(line));
}


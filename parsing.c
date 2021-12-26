/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:40:18 by fathjami          #+#    #+#             */
/*   Updated: 2021/12/26 11:49:37 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int filename(char *str)
{
	char *p;

	p = ft_memchr(str, '.');
	return (ft_strcmp(p, ".ber"));
}

int one_set_len(char **map)
{
	int i;
	int j;
	int res[3];

	i = 0;
	l = len(map[0]);
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	while (map[i] && len(map[i]) == l)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				res[0]++;
			else if (map[i][j] == 'C')
				res[1]++;
			else if ( map[i][j] == 'P')
				res[2]++;
			else if(map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (res[0] > 1 && res[1] > 1 && res[2] > 1);
}

int walls(char **map)
{
	int i;
	int j;
	int l;

	i = 0;
	l = len (map[0])
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			
		}
	}
}

int main(int ac, char **av)
{
	int fd;
	char *line;
	int count;
	int i;
	char **map;

	line = duup("");
	i = 0;
	count = 0;
	if(ac == 2 && !filename(av[1]))
	{
		fd = open(av[1], O_RONLY);
		while (line != NULL)
		{
			line = get_next_line(fd);
			count++;
		}
		close(fd);
		fd = open(av[1], O_RONLY);
		map = malloc(sizeof(char *) *  (count + 1));
		map[count] = 0;
		while (i < count)
			map[i++] = get_next_line(fd);
		close (fd);
		return (check_map(map));
	}
	return (0);
}

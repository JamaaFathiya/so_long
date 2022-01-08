/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:40:18 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/08 13:02:38 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_all(t_mp *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i] && len(m->map[i]) == m->c)
	{
		j = 0;
		while (m->map[i][j])
		{
			player_position(m, i, j);
			if (m->map[i][j] == 'E')
				m->exit = true;
			else if (m->map[i][j] == 'C')
				m->coll = true;
			else if (m->map[i][j] == 'P')
				m->start = true;
			else if (m->map[i][j] != '0' && m->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (m->exit && m->coll && m->start);
}

int	check_walls(t_mp m)
{
	int	i;
	int	j;

	i = 0;
	while (m.map[i])
	{
		j = 0;
		while (m.map[i][j])
		{
			if (i == 0 || i == m.l - 1 || j == 0 || j == m.c - 1)
				if (m.map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_extension(char *str)
{
	int		i;
	char	*ex;
	int		j;

	i = len(str) - 1;
	ex = "reb.";
	j = 0;
	while (i >= 0 && ex[j] == str[i])
	{
		j++;
		i--;
		if (j == len(ex))
			return (1);
	}
	return (0);
}

void	check_map(char *str, t_mp *m)
{
	int	cmp;

	cmp = check_extension(str);
	m->count = count_coll(*m);
	if (!check_all(m))
		printf("Error!\nPlease make sure your map contains only '1','0' and at\
 least a 'P','C','E'.");
	else if (!check_walls(*m))
		printf("Error!\nCheck your walls please.");
	else if (!cmp)
		printf("Error!\nMake sure that your filename format is *.ber.");
	else
	{
		printf("Valid map!\n");
		return ;
	}
	exit (1);
}

t_mp	get_check_map(char *str)
{
	int		fd;
	int		i;
	t_mp	m;

	i = 0;
	is_dir(str);
	fd = open(str, O_RDONLY);
	m.l = map_len(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	m.map = malloc(sizeof(char *) * (m.l + 1));
	m.map[m.l] = 0;
	while (i < m.l)
		m.map[i++] = get_next_line(fd);
	m.c = len(m.map[0]);
	close (fd);
	check_map(str, &m);
	return (m);
}

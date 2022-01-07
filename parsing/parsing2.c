/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:13:22 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/07 14:36:59 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_dir(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error!\n%s : is a directory\n", str);
		exit (1);
	}
	close (fd);
}

void player_position(t_mp *m, int i, int j)
{
	if (m->map[i][j] == 'P')
	{
		m->p_y = i;
		m->p_x = j;		
	}
}

int map_len(int fd)
{
	char *line;
	int count;

	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	return (count);
}

int	count_coll(t_mp m)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (m.map[i])
	{
		j = 0;
		while (m.map[i][j])
		{
			if (m.map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

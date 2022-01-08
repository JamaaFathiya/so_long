/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:36:26 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/08 18:27:21 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*path(char c, t_data *param)
{
	char	*path;

	path = NULL;
	if (c == '1')
		path = "assets/wall.xpm";
	else if (c == 'E')
	{
		if (param->m.count == 0)
			path = "assets/door_opened.xpm";
		else
			path = "assets/door.xpm";
	}
	else if (c == 'P')
		path = "assets/player.xpm";
	else if (c == 'C')
		path = "assets/collect.XPM";
	else if (c == 'X')
		path = enemy(param);
	else
		return (NULL);
	return (path);
}

char	*enemy(t_data *param)
{
	char	*path;
	
	path = NULL;
	if (param->m.enemy == 1)
	{
		path = "assets/slime1.xpm";
		param->m.enemy = 2;
	}
	
	else if (param->m.enemy == 2)
	{
		path = "assets/slime2.xpm";
		param->m.enemy = 3;
	}
	else if (param->m.enemy == 3)
	{
		path = "assets/slime3.xpm";
		param->m.enemy = 4;
	}
	else if (param->m.enemy == 4)
	{
		path = "assets/slime4.xpm";
		param->m.enemy = 1;
	}
	return (path);
}

void	image(char *relative_path, t_data param, int i, int j)
{
	int		img_width;
	void	*img;

	img_width = SQUARE;
	img = mlx_xpm_file_to_image(param.mlx,
			relative_path, &img_width, &img_width);
	mlx_put_image_to_window (param.mlx, param.mlx_win, img,
		j * img_width, i * img_width);
	mlx_destroy_image(param.mlx, img);
}

int	fill_map(t_data *param)
{
	int		i;
	int		j;
	char	*relative_path;

	i = 0;
	while (param->m.map[i])
	{
		j = 0;
		while (param->m.map[i][j])
		{
			relative_path = path(param->m.map[i][j], param);
			if (relative_path)
				image(relative_path, *param, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

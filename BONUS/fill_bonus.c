/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:36:26 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/10 12:20:16 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*path(char c, t_data *param)
{
	char	*path;

	path = NULL;
	if (c == '1')
		path = "assets_bonus/wall.xpm";
	else if (c == 'E')
	{
		if (param->m.count == 0)
			path = "assets_bonus/door_opened.xpm";
		else
			path = "assets_bonus/door.xpm";
	}
	else if (c == 'P')
		path = "assets_bonus/player.xpm";
	else if (c == 'C')
		path = "assets_bonus/collect.XPM";
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
	if (param->m.enemy >= 0 && param->m.enemy <= FRAME)
		path = "assets_bonus/enemy1.xpm";
	else if (param->m.enemy >= FRAME && param->m.enemy < FRAME * 2)
		path = "assets_bonus/enemy2.xpm";
	else if (param->m.enemy == FRAME * 2)
	{
		path = "assets_bonus/enemy2.xpm";
		param->m.enemy = 0;
	}
	param->m.enemy++;
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
	mlx_clear_window(param->mlx, param->mlx_win);
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
	mlx_string_put(param->mlx, param->mlx_win, (((param->m.c - 1) * SQUARE) / 2)
		- SQUARE, param->m.l * SQUARE, 0xff0000, ft_itoa(param->moves));
	return (0);
}

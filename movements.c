/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:37:09 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/08 12:52:07 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *param)
{
	char	temp;

	if (param->m.map[param->m.p_y - 1][param->m.p_x] == '0')
	{
		temp = param->m.map[param->m.p_y][param->m.p_x];
		param->m.map[param->m.p_y][param->m.p_x]
			=param->m.map[param->m.p_y - 1][param->m.p_x];
		param->m.map[param->m.p_y - 1][param->m.p_x] = temp;
		param->m.p_y--;
	}
	else if (param->m.map[param->m.p_y - 1][param->m.p_x] == 'E')
	{
		if (param->m.count == 0)
			free_all(param);
	}
	else if (param->m.map[param->m.p_y - 1][param->m.p_x] == 'C')
	{
		param->m.count--;
		param->m.map[param->m.p_y - 1][param->m.p_x] = 'P';
		param->m.map[param->m.p_y][param->m.p_x] = '0';
		param->m.p_y--;
	}
}

void	move_down(t_data *param)
{
	char	temp;

	if (param->m.map[param->m.p_y + 1][param->m.p_x] == '0')
	{
		temp = param->m.map[param->m.p_y][param->m.p_x];
		param->m.map[param->m.p_y][param->m.p_x]
			=param->m.map[param->m.p_y + 1][param->m.p_x];
		param->m.map[param->m.p_y + 1][param->m.p_x] = temp;
		param->m.p_y++;
	}
	else if (param->m.map[param->m.p_y + 1][param->m.p_x] == 'E')
	{
		if (param->m.count == 0)
			free_all(param);
	}
	else if (param->m.map[param->m.p_y + 1][param->m.p_x] == 'C')
	{
		param->m.count--;
		param->m.map[param->m.p_y + 1][param->m.p_x] = 'P';
		param->m.map[param->m.p_y][param->m.p_x] = '0';
		param->m.p_y++;
	}
}

void	move_left(t_data *param)
{
	char	temp;

	if (param->m.map[param->m.p_y][param->m.p_x - 1] == '0')
	{
		temp = param->m.map[param->m.p_y][param->m.p_x];
		param->m.map[param->m.p_y][param->m.p_x]
			=param->m.map[param->m.p_y][param->m.p_x - 1];
		param->m.map[param->m.p_y][param->m.p_x - 1] = temp;
		param->m.p_x--;
	}
	else if (param->m.map[param->m.p_y][param->m.p_x - 1] == 'E')
	{
		if (param->m.count == 0)
			free_all(param);
	}
	else if (param->m.map[param->m.p_y][param->m.p_x - 1] == 'C')
	{
		param->m.count--;
		param->m.map[param->m.p_y][param->m.p_x - 1] = 'P';
		param->m.map[param->m.p_y][param->m.p_x] = '0';
		param->m.p_x--;
	}
}

void	move_right(t_data *param)
{
	char	temp;

	if (param->m.map[param->m.p_y][param->m.p_x + 1] == '0')
	{
		temp = param->m.map[param->m.p_y][param->m.p_x];
		param->m.map[param->m.p_y][param->m.p_x]
			=param->m.map[param->m.p_y][param->m.p_x + 1];
		param->m.map[param->m.p_y][param->m.p_x + 1] = temp;
		param->m.p_x++;
	}
	else if (param->m.map[param->m.p_y][param->m.p_x + 1] == 'E')
	{
		if (param->m.count == 0)
			free_all(param);
	}
	else if (param->m.map[param->m.p_y][param->m.p_x + 1] == 'C')
	{
		param->m.count--;
		param->m.map[param->m.p_y][param->m.p_x + 1] = 'P';
		param->m.map[param->m.p_y][param->m.p_x] = '0';
		param->m.p_x++;
	}
}

int	move(int key, t_data *param)
{
	if (key == ESC_KEY)
		free_all(param);
	if (key == W_KEY)
		move_up(param);
	else if (key == S_KEY)
		move_down(param);
	else if (key == A_KEY)
		move_left(param);
	else if (key == D_KEY)
		move_right(param);
	mlx_clear_window(param->mlx, param->mlx_win);
	fill_map(*param);
	return (0);
}

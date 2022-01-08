/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:38:14 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/08 09:05:21 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(int key, t_data *param)
{
	if (key == W_KEY)
	{
		mlx_clear_window(param->mlx, param->mlx_win);
		move_up(param);
		fill_map(*param);
	}
	else if (key == S_KEY)
	{
		mlx_clear_window(param->mlx, param->mlx_win);
		move_down(param);
		fill_map(*param);
	}
	else if (key == A_KEY)
	{
		mlx_clear_window(param->mlx, param->mlx_win);
		move_left(param);
		fill_map(*param);
	}
	else if (key == D_KEY)
	{
		mlx_clear_window(param->mlx, param->mlx_win);
		move_right(param);
		fill_map(*param);
	}
}

int	play(int key, t_data *param)
{
	destroy(key, param);
	movement(key, param);
	return (0);
}

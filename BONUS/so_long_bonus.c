/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:01:31 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/10 12:12:47 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_win(t_data *param)
{
	free_all(param);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*param;

	param = malloc(1 * sizeof(t_data));
	if (ac == 2)
	{
		param->moves = 0;
		param->m = get_check_map(av[1]);
		param->mlx = mlx_init();
		param->mlx_win = mlx_new_window(param->mlx,
				param->m.c * SQUARE, (param->m.l + 1) * SQUARE, "So Long");
		if (param->m.e == true)
			 mlx_loop_hook(param->mlx, &fill_map, param);
		mlx_hook(param->mlx_win, CLS_KEY, 0, &close_win, param);
		mlx_hook (param->mlx_win, 2, 0, &move, param);
		mlx_loop(param->mlx);
	}
}

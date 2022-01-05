/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:01:31 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/05 18:04:58 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int destroy(int key, t_data *param)
{
	printf("Key: %d\n",key);
	if (key == ESC_KEY)
	{
		mlx_destroy_window(param->mlx, param->mlx_win);
		printf("See you :)\n");
		exit (0);
	}
	return (0);
}

int close_win()
{
	printf("See you :)\n");
	//free_all(all);
	exit (1);
	return (0);
}


int main(int ac, char **av)
{
	t_data param;

	t_mp m;


	if (ac == 2)
	{
		m = get_check_map(av[1]);
		param.mlx = mlx_init();
		param.mlx_win = mlx_new_window(param.mlx, m.c * SQUARE, m.l * SQUARE, "So Long");
		fill_map(param, m);
		mlx_key_hook (param.mlx_win, &destroy , &param);
		mlx_hook(param.mlx_win, CLS_KEY, 0, &close_win, &param);
		mlx_loop(param.mlx);
	}
}

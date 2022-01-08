/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:24:52 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/08 10:31:46 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *param)
{
	int	i;

	i = 0;
	if (param->m.count == 0)
		printf("Let's goo! You won duude. :)\n");
	else
		printf("See you :)\n");
	while (param->m.map[i])
		free(param->m.map[i++]);
	free(param->m.map);
	mlx_destroy_window(param->mlx, param->mlx_win);
	exit (0);
}

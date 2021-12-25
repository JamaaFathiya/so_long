/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:14:24 by fathjami          #+#    #+#             */
/*   Updated: 2021/12/21 14:19:03 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}	t_data;

int destroy(int key, t_data *param)
{
	printf("Key: %d\n",key);
	mlx_destroy_window(param->mlx, param->mlx_win);
	return (0);
}

int main()
{
	void	*img;
	t_data param;
	char	*relative_path = "/Users/fathjami/Downloads/tiny.XPM";
	int		img_width;
	int		img_height;
	int a;
	int b;

	a = 10;
	b= 10;

	img_width = 10;
	img_height = 10;

	param.mlx = mlx_init();
	param.mlx_win = mlx_new_window(param.mlx, 1000, 900, "So Long");
	mlx_key_hook (param.mlx_win, &destroy , &param);
	img = mlx_xpm_file_to_image(param.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window (param.mlx, param.mlx_win, img, 0 ,0);
	mlx_loop(param.mlx);
}

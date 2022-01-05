/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:52:27 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/05 14:30:55 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define SQUARE 32
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53
# define CLS_KEY 17

typedef struct mp
{
	bool	coll;
	bool	exit;
	bool	start;
	char	**map;
	int		c;
	int		l;
}	t_mp;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}	t_data;

typedef struct
{
	t_data param;
	t_mp m;
}	t_all;


char 	*get_next_line(int fd);
int 	len(char *str);
void    *ft_memchr(const void *s, int c, size_t n);
int 	 ft_strcmp(char *s1, char *s2);
char	 *duup(char *str);
void	*ft_memset(void *b, int c);
t_mp    get_check_map(char *str);
void    is_dir(char *str);
void fill_map(t_data param, t_mp m);
void free_all(t_all all);
# endif

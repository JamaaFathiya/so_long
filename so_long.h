/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:52:27 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/07 18:29:10 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
	int		count;
	int		p_x;
	int		p_y;
}	t_mp;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_mp	m;
}	t_data;

t_mp	get_check_map(char *str);
char	*get_next_line(int fd);
char	*duup(char *str);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c);
void	is_dir(char *str);
void	fill_map(t_data param);
void	player_position(t_mp *m, int i, int j);
void	move_up(t_data *param);
void	move_left(t_data *param);
void	move_down(t_data *param);
void	move_right(t_data *param);
int		len(char *str);
int		ft_strcmp(char *s1, char *s2);
int		count_coll(t_mp m);
int		play(int key, t_data *param);
int		map_len(int fd);
int		destroy(int key, t_data *param);
int		play(int key, t_data *param);
#endif

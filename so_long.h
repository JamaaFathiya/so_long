/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:52:27 by fathjami          #+#    #+#             */
/*   Updated: 2021/12/26 10:22:23 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
char *get_next_line(int fd);
int len(char *str);
void    *ft_memchr(const void *s, int c, size_t n);
int  ft_strcmp(char *s1, char *s2);
char *duup(char *str);

# endif

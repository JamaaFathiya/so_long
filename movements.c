/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:37:09 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/07 18:49:27 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *param)
{
    char temp;
    
    if (param->m.map[param->m.p_y - 1][param->m.p_x] == '0')
    {
        temp = param->m.map[param->m.p_y][param->m.p_x];
        param->m.map[param->m.p_y][param->m.p_x] = param->m.map[param->m.p_y - 1][param->m.p_x];
        param->m.map[param->m.p_y - 1][param->m.p_x] = temp;
        param->m.p_y--;
    }
    else if (param->m.map[param->m.p_y - 1][param->m.p_x] == 'E')
    {
        if (param->m.count == 0)
            exit(0);
    }
    else if (param->m.map[param->m.p_y - 1][param->m.p_x] == 'C')
    {
        param->m.count--;
        param->m.map[param->m.p_y - 1][param->m.p_x] = 'P';
        param->m.map[param->m.p_y][param->m.p_x] = '0';
        param->m.p_y--;
    }
    return ;
}

void    move_down(t_data *param)
{
    char temp;
    
    if (param->m.map[param->m.p_y + 1][param->m.p_x] == '0')
    {
        temp = param->m.map[param->m.p_y][param->m.p_x];
        param->m.map[param->m.p_y][param->m.p_x] = param->m.map[param->m.p_y + 1][param->m.p_x];
        param->m.map[param->m.p_y + 1][param->m.p_x] = temp;
        param->m.p_y++;
    }
    else if (param->m.map[param->m.p_y + 1][param->m.p_x] == 'E')
    {
        if (param->m.count == 0)
            exit(0);
    }
    else if (param->m.map[param->m.p_y + 1][param->m.p_x] == 'C')
    {
        param->m.count--;
        param->m.map[param->m.p_y + 1][param->m.p_x] = 'P';
        param->m.map[param->m.p_y][param->m.p_x] = '0';
        param->m.p_y++;
    }
    return ;
}

void    move_left(t_data *param)
{
    char temp;
    
    if (param->m.map[param->m.p_y][param->m.p_x - 1] == '0')
    {
        temp = param->m.map[param->m.p_y][param->m.p_x];
        param->m.map[param->m.p_y][param->m.p_x] = param->m.map[param->m.p_y][param->m.p_x - 1];
        param->m.map[param->m.p_y][param->m.p_x - 1] = temp;
        param->m.p_x--;
    }
    else if (param->m.map[param->m.p_y][param->m.p_x - 1] == 'E')
    {
        if (param->m.count == 0)
            exit(0);
    }
    else if (param->m.map[param->m.p_y][param->m.p_x - 1] == 'C')
    {
        param->m.count--;
        param->m.map[param->m.p_y][param->m.p_x - 1] = 'P';
        param->m.map[param->m.p_y][param->m.p_x] = '0';
        param->m.p_x--;
    }
    return ;
}

void    move_right(t_data *param)
{
    char temp;
    
    if (param->m.map[param->m.p_y][param->m.p_x + 1] == '0')
    {
        temp = param->m.map[param->m.p_y][param->m.p_x];
        param->m.map[param->m.p_y][param->m.p_x] = param->m.map[param->m.p_y][param->m.p_x + 1];
        param->m.map[param->m.p_y][param->m.p_x + 1] = temp;
        param->m.p_x++;
    }
    else if (param->m.map[param->m.p_y][param->m.p_x + 1] == 'E')
    {
        if (param->m.count == 0)
            exit(0);
    }
    else if (param->m.map[param->m.p_y][param->m.p_x + 1] == 'C')
    {
        param->m.count--;
        param->m.map[param->m.p_y][param->m.p_x + 1] = 'P';
        param->m.map[param->m.p_y][param->m.p_x] = '0';
        param->m.p_x++;
    }
}

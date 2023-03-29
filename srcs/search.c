/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:45 by marai             #+#    #+#             */
/*   Updated: 2023/03/29 22:15:32 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_start(t_vars *vars)
{
	ssize_t	x;
	ssize_t	y;

	y = 0;
	while (vars->line[y])
	{
		x = 0;
		while (vars->line[y][x].value)
		{
			if (vars->line[y][x].value == 'P')
			{
				vars->player_x = x;
				vars->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	search(t_line **line, ssize_t x, ssize_t y)
{
	if (!line[x])
		return ;
	if (!line[x][y].value || line[x][y].value == 'E' || line[x][y].value == '1'
		|| line[x][y].is_checked == 1)
	{
		line[x][y].is_checked = 1;
		return ;
	}
	line[x][y].is_checked = 1;
	if (line[x + 1] && line[x + 1][y].value && line[x + 1][y].is_checked == 0)
		search(line, x + 1, y);
	if (line[x][y + 1].value && line[x][y + 1].is_checked == 0)
		search(line, x, y + 1);
	if (x - 1 >= 0 && line[x - 1][y].value && line[x - 1][y].is_checked == 0)
		search(line, x - 1, y);
	if (y - 1 >= 0 && line[x][y - 1].value && line[x][y - 1].is_checked == 0)
		search(line, x, y - 1);
	return ;
}

void	check_C(t_line **line)
{
	ssize_t	x;
	ssize_t	y;

	x = 0;
	while (line && line[x])
	{
		y = 0;
		while (line[x][y].value)
		{
			if (line[x][y].value == 'C' && line[x][y].is_checked == 0)
				err_so_long("2 invalid map");
			if (line[x][y].value == 'E' && line[x][y].is_checked == 0)
				err_so_long("4 invalid map");
			y++;
		}
		x++;
	}
}

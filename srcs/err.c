/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:33:44 by marai             #+#    #+#             */
/*   Updated: 2023/04/02 15:18:01 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_paras(t_line **line, char chr, const ssize_t count);

void	err_so_long(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	check_compose(t_line **line)
{
	ssize_t	x;
	ssize_t	y;
	char	chr;

	y = 0;
	while (line && line[y])
	{
		x = 0;
		while (line[y][x].value)
		{
			chr = line[y][x].value;
			if (chr != '0' && chr != '1' && chr != 'E' && chr != 'C'
				&& chr != 'P')
				line_free_exit(line,
					"Error\nmaps must be made by 0, 1, E, P, C");
			x++;
		}
		y++;
	}
	check_paras(line, 'E', 1);
	check_paras(line, 'P', 1);
	check_paras(line, 'C', 0);
}

void	check_paras(t_line **line, char chr, const ssize_t count)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	nums;

	nums = 0;
	y = 0;
	while (line && line[y])
	{
		x = 0;
		while (line[y][x].value)
		{
			if (chr == line[y][x].value)
				nums++;
			x++;
		}
		y++;
	}
	if ((0 < count && nums != count) || (count == 0 && nums <= 0))
		line_free_exit(line, "Error\ninvalid map");
}

int	escape(t_vars *vars)
{
	line_free(vars->line, vars->map_height);
	exit(0);
	return (0);
}

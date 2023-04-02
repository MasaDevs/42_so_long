/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:51:21 by marai             #+#    #+#             */
/*   Updated: 2023/04/02 15:19:30 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(t_map *map)
{
	t_map	*next_map;

	while (map)
	{
		next_map = map->next;
		free(map->line);
		free(map);
		map = next_map;
	}
}

void	line_free(t_line **line, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void	line_free_exit(t_line **line, char *str)
{
	ssize_t	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line[i]);
	free(line);
	err_so_long(str);
}

void	image_free(t_vars *vars)
{
	if (vars->img_red.img)
		mlx_destroy_image(vars->mlx, vars->img_red.img);
	if (vars->img_green.img)
		mlx_destroy_image(vars->mlx, vars->img_green.img);
	if (vars->img_yellow.img)
		mlx_destroy_image(vars->mlx, vars->img_yellow.img);
	if (vars->img_blue.img)
		mlx_destroy_image(vars->mlx, vars->img_blue.img);
	if (vars->img_pink.img)
		mlx_destroy_image(vars->mlx, vars->img_pink.img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:51:21 by marai             #+#    #+#             */
/*   Updated: 2023/03/31 10:44:06 by Marai            ###   ########.fr       */
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

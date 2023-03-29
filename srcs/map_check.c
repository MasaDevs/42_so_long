/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:52:09 by marai             #+#    #+#             */
/*   Updated: 2023/03/30 00:56:30 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(char *str)
{
	while (str)
	{
		str = ft_strnstr(str, ".ber", ft_strlen(str));
		if (!str)
			break ;
		if (ft_strlen(str) == 4)
			return ;
		str++;
	}
	err_so_long("file extension must be '.ber'");
}

ssize_t	check_shapes(t_map *map)
{
	ssize_t	count;

	if (!map)
		err_so_long("map doesn't exist");
	map = map->next;
	count = 0;
	while (map)
	{
		if (!ft_strlen(map->line))
			break ;
		count++;
		map = map->next;
	}
	return (count);
}

void	is_rectangle(t_map *map)
{
	ssize_t	map_len;
	ssize_t	len;
	ssize_t	flags;

	if (!map || !map->next || !map->next->line)
	{
		map_free(map);
		err_so_long("map doesn't exist");
	}
	map = map->next;
	map_len = ft_strlen(map->line);
	flags = 0;
	while (map)
	{
		len = ft_strlen(map->line);
		if (len == 0)
			flags = 1;
		if ((map_len != len && flags == 0) || (len != 0 && flags == 1))
		{
			map_free(map);
			err_so_long("this map is not rectangle");
		}
		map = map->next;
	}
}

static void	edge_check(t_map *map, t_map *map_head)
{
	ssize_t	i;

	i = 0;
	while (map->line && map->line[i])
	{
		if (map->line[i] != '1')
		{
			map_free(map_head);
			err_so_long("map is not sorrounded by 1");
		}
		i++;
	}
}

void	is_sorrounded(t_map *map)
{
	t_map	*map_head;

	map_head = map;
	if (!map || !map->next || !map->next->line)
	{
		map_free(map_head);
		err_so_long("map doesn't exist");
	}
	map = map->next;
	edge_check(map, map_head);
	map = map->next;
	while (map && map->next)
	{
		if (!map->line || !ft_strlen(map->line))
			break ;
		if (!map->line || map->line[0] != '1'
			|| map->line[ft_strlen(map->line) - 1] != '1')
		{
			map_free(map_head);
			err_so_long("map is not sorrounded by 1");
		}
		map = map->next;
	}
	edge_check(map, map_head);
}
